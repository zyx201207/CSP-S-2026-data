#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int v;
	ll x;
};
vector<node>dian[500010];
ll c,n,m,d,q,cdu;
ll t[511][511];
ll crz[500010];
ll ans;
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(t,7,sizeof(t));
	cin>>c>>n>>m>>d>>q;
	if(m==1)
	{
		for(ll i=1;i<=q;i++)cout<<0<<endl;
		return 0;
	}
	for(ll i=1;i<=m;i++)cin>>crz[i];
	node no,ne;
	for(int i=1,x;i<=n;i++)
	{
		cin>>cdu;ne.v=i;
		for(int j=1;j<=cdu;j++)
		{
			cin>>x>>ne.x;
			dian[x].push_back(ne);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cdu=dian[i].size();
		for(int j=0;j<cdu;j++)
		{
			no=dian[i][j];
			for(int k=j+1;k<cdu;k++)
			{
				ne=dian[i][k];
				t[no.v][ne.v]=min(t[no.v][ne.v],no.x+ne.x);
				t[ne.v][no.v]=min(t[ne.v][no.v],no.x+ne.x);	
			}
		}
	}
	for(int i=1;i<=n;i++)t[i][i]=0ll;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k=1;k<=n;k++)
			{
				if(i==k or j==k)continue;
				t[i][j]=min(t[i][j],t[i][k]+t[j][k]);
			}
		}
	}
	int u,v,lu,lv;
	while(q--)
	{
		ans=(ll)1e17;
		cin>>u>>v;
		lu=dian[u].size();lv=dian[v].size();
		for(int i=0;i<lu;i++)
		{
			no=dian[u][i];
			for(int j=0;j<lv;j++)
			{
				ne=dian[v][j];
				ans=min(ans,t[no.v][ne.v]+no.x+ne.x);
			}
		}
		ans+=crz[u]+crz[v];
		cout<<ans<<endl; 
	}
	return 0;
}
