#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans,a[N];
vector<vector<int>> pre(35);
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		pre[31].push_back(a[i]);
	}
	for(int i=31;i>=1;i--) {
		int num=0;
		for(auto x:pre[i]) {
			if(((x>>(i-1))&1)==1) num++;
		}
		if(num<m) {
			for(auto x:pre[i]) {
				pre[i-1].push_back(x);
			}
			continue;
		}
		ans+=(1<<(i-1));
		for(auto x:pre[i]) {
			if(((x>>(i-1))&1)==1) pre[i-1].push_back(x);
		}
	}
	cout<<ans;
	return 0;
}
