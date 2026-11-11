#include<bits/stdc++.h>
using namespace std;
int n,u;
int a[200005];
long long f[800005];
long long k[800005];
long long ma=-1000;
void dfs(int t,long long sum) {
	if(t==u) {
		ma=max(ma,sum);
		return ;
	}
	if(t==0) {
		for(int i=1; i<=n; i++) {
			int p=a[i];
			f[a[i]]++;
			if(f[a[i]]==1)dfs(t+1,a[i]);
			f[a[i]]--;
		}
	} else {
		for(int i=1; i<=n; i++) {
			int p=a[i];
			f[a[i]]++;
			if(f[a[i]]==1)dfs(t+1,(sum&a[i]));
			f[a[i]]--;
		}
	}
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,0,sizeof f);
	cin>>n>>u;
	for(int i=1; i<=n; i++)cin>>a[i];
    dfs(0,0);
    cout<<ma;
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12

*/
