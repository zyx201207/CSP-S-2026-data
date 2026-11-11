#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans = 0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200002];
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 30;i >= 0;i--){
		vector<int> vec;
		for (int j = 1;j <= n;j++){
			if (a[j] & (1 << i)){
				vec.push_back(a[j]);
//				cout << a[j] << ' ' << (1 << i) << ' ';
			}
		}
		if (vec.size() >= m){
			n = vec.size();
			for (int i = 1;i <= vec.size();i++){
				a[i] = vec[i - 1];
			}
			ans += (1 << i);
		}
		vec.clear();
	}
	cout << ans;
}
