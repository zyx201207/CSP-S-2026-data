#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
struct node
{
	int to,e;
};
int w[500005],dist[500005],a[505][500005];
vector<node> g[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c>=1&&c<=3)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			int t,u,w;
			cin>>t;
			for(int j=1;j<=t;j++)
			{
				cin>>u>>w;
				a[i][u]=w;
			} 
		}
		memset(dist,0x3f3f3f3f,sizeof(dist));
		for(int i=1;i<=q;i++)
		{
			int s,t;
			cin>>s>>t;
			if(s<t)
			{
				for(int i=1;i<=n;i++)
				{
					continue; 
				}
			}
		}
		
	}
	cout<<0;
	return 0;
 } 
