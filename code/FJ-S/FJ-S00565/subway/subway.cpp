#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500000;
int p,n,m,d,q;
int a[N],b[N],c[N];
int ans=1e18;
vector<pair<int,int>> op[N];
void dfs(int l,int r,int g)
{
	int k=op[l].size();
	if(l==r)
	{
		for(int i=0;i<k;i++)
		ans=min(ans,g+op[l][i].second);
		return;
	}
	if(l>r)
	return;
	for(int i=0;i<k;i++)
	{
		dfs(op[l][i].first,r,g+op[l][i].second);
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>p>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>b[j]>>c[j];
		}
		for(int j=1;j<=k;j++)
		op[b[j]].push_back({b[j+1],c[j]});
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		dfs(l,r,0);
		cout<<ans+a[l]+a[r]<<endl;
		ans=1e18;
	}
	return 0;
}
//燃尽了，做不出来 
