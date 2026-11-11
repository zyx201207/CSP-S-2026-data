#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int tag[500005],ans[500005];
int nxt[500005],lst[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i;
	for(int i=1;i<=n;i++) nxt[i]=lst[a[i]];
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]!=i)
		{
			tag[i]++;
			tag[nxt[i]]+=tag[i];
		}
		else
		{
			tag[i]++;
			ans[a[i]]+=tag[i];
			tag[i+1]+=tag[i];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

