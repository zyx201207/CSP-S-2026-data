#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c,n,m,d,q,x,ex,ans,xx;
int ti[N],k[N],ch[N];
bool vis[N];
struct su
{
	int a,t;
}s[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ti[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>s[i][j].a>>s[i][j].t;
			ch[s[i][j].a]++;
		}
	}
	while(q--)
	{
		ans=0;
		cin>>x>>ex;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)
			{
				if(s[i][j].a==x)
				{
					ans+=ti[i];
				}		
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(s[i][j].a!=x&&ch[s[i][j].a]==1)
					ans+=s[i][j].t;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)
			{
				if(s[i][j].a==ex)
				{
					ans+=ti[i];
				}		
			}
		cout<<ans;
	}
	return 0;
}
