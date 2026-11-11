#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[500005],cnt[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],lst[a[i]]=i,cnt[i]=1;
	for(int i=1;i<=n;i++)ans[a[i]]+=cnt[i],cnt[lst[a[i]]+1]+=cnt[i];
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
