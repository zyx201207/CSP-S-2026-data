#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500004;
ll c,n,m,d,q,ans=0;
ll w[MAXN],a[500][MAXN/2],t[500][MAXN/2],qd[100005],zd[100005],x[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		for(int j=1;j<=x[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qd[i]>>zd[i];
		ans+=w[qd[i]];
		for(int j=1;j<=x[i];j++)
		{
			for(int o=1;o<=n;o++)
			{
				if(a[j][o]==qd[i])
				{
					ans+=t[j][o];
				}
			}
			for(int o=1;o<=n;i++)
			{
				if(a[j][o]==zd[i])
				{
					ans+=w[zd[i]]+t[j][o];
					cout<<ans;
					return 0;
				}
				else
				{
					ans+=t[j][o];
				}
			}
		}
	}
	return 0;
}
