#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans[300005];
int sum[500005];
int f[500005];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
		if(mp.count(a[i])) f[i]=mp[a[i]],++sum[mp[a[i]]];
		else f[i]=i,++sum[i],mp[a[i]]=i;
	for(int i=1;i<=n;i++) if(f[i]==i) ans[a[i]]+=sum[i],sum[f[i+1]]+=sum[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
