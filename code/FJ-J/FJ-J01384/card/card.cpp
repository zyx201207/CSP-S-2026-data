#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],k[300005],cnt[500005],ans[300005];vector<int>g[300005];
signed main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout),cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],g[a[i]].push_back(i),cnt[i]=k[a[i]]++;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(cnt[j]+1<g[a[j]].size())j=g[a[j]][cnt[j]+1]-1;else ans[a[j]]++;
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
