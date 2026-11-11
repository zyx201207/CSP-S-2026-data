#include<bits/stdc++.h>
using namespace std;
int ma;
const int mxn=20010;
int c,n,m,d,q;
long long w[mxn];
//struct node
//{
//	long long id,val;
//};
//vector<node > mp[510];		
long long dis[610][610];
int ml;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//cout<<(&ml-&ma)/1024;
	cin>>c>>n>>m>>d>>q;

		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=1e18;
			}
		}		
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
					long long x1,val,x2,val2;
					cin>>x1>>val>>x2>>val2;
					dis[x1][x2]=dis[x2][x1]=min(dis[x1][x2],val+val2);
		}
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=m;k++)
					{
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
		int l,r;
		for(int i=1;i<=q;i++)
		{
			cin>>l>>r;
			cout<<dis[l][r]+w[l]+w[r]<<endl;
		}		
	return 0;
}
