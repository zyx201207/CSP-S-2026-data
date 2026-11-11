#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],c[N],d[N],ls[N],to[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],c[i]=1;
	for(int i=1;i<=m;++i)ls[i]=n+1;
	for(int i=n;i;--i)to[i]=ls[a[i]],ls[a[i]]=i;
	memset(ls,0,sizeof ls),ls[n+1]=n+1;
	for(int i=n;i;--i)ls[i]=to[i]<=n?i:ls[i+1];
	for(int i=1;i<=n;++i)d[i]+=c[i]+d[i-1],d[ls[i]]-=c[i],c[to[ls[i]]]+=c[i],ans[a[i]]+=d[i];
	for(int i=1;i<=m;++i)cout<<ans[i]<<" \n"[i==m];
	return 0;
}
