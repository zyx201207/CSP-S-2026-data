#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<long long> nums;
vector<int> sheet[35];
vector<int> anss;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int num0;
	for (int i=0;i<n;i++) {
		cin >> num0;
		nums.push_back(num0);
		int j=0;
		while (num0>0) {
			if (num0%2==1) {
				sheet[j].push_back(i);
			}
			num0/=2;
			j++;
		}
	}
	long long ans;
	for (int i=30;i>=0;i--) {
		if (int(sheet[i].size())>=m) {
			if (anss.empty()) {
				anss = sheet[i];
			} else {
				vector<int> same;
				same.clear();
				for (int j=0;j<int(anss.size());j++) {
					for (int k=0;k<int(sheet[i].size());k++) {
						if (anss[j]==sheet[i][k]) {
							same.push_back(anss[j]);
							continue;
						}
						if (anss[j]<sheet[i][k]) {
							continue;
						}
					}
				}
				if (int(same.size())>=m) {
					anss = same;
				}
			}
		}
		if (int(anss.size())==m) {
			break;
		}
	}
	ans = nums[anss[0]];
	for (int i=1;i<int(anss.size());i++) {
		ans = ans&nums[anss[i]];
	}
	cout << ans;
	return 0;
}
