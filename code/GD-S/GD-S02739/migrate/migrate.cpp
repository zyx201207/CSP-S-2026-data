#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int INF=0x3f3f3f3f;
const int N=2e6+10;
int c,t;
int n,d;
int x[N],mn=INT_MAX,ans;
void dfs1(int idx,int s)
{
	if(idx==n) 
	{
		mn=min(mn,s);
		return ;
	}
	for(int i=idx+1;i<=n;i++)
	{
		if(i-idx<=d) dfs1(i,s+1);
		else break;
	}
}
void dfs2(int idx,int s)
{
	if(idx==n && s==mn) 
	{
		ans++;
		return ;
	}
	for(int i=idx+1;i<=n;i++)
	{
		if(i-idx<=d) dfs2(i,s+1);
		else break;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		mn=INT_MAX;
		dfs1(1,0);
		dfs2(1,0);
		cout<<ans<<" ";
	}
	return 0;
}
