#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct node{
	int u;
	int v;
};

int times[300005];
int place[300005];
int nums[500005];
vector<node> ns;
vector<node> n0;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> nums[i];
		if(place[nums[i]]!=0) {
			node nn = {place[nums[i]],i-1};
			ns.push_back(nn);
			place[nums[i]]=0;
		} else {
			place[nums[i]]=i;
		}
	}
	int idx=ns.size()-1;
	for (int i=n;i>=1;i--) {
		if (i<ns[idx].u) {
			if (n0.empty()) {
				n0.push_back(ns[idx]);
			} else {
				if (ns[idx].v>n0.back().u) {
					n0[n0.size()-1] = ns[idx];
				} else {
					n0.push_back(ns[idx]);
				}
			}
			idx--;
		}
		int k=0;
		for (int j=n;j>=i;j--) {
			if (!n0.empty()) {
				if (j<n0[k].u) {
					k++;
				}
				if (j>=n0[k].u&&j<=n0[k].v) {
					continue;
				}
			}
			times[nums[j]]++;
		}
	}
	for (int i=1;i<=m;i++) {
		cout << times[i] << ' ';
	}
	return 0;
}
