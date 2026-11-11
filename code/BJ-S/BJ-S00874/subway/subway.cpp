#include<bits/stdc++.h>
using namespace std;
struct route
{
	int plat;//the platform that can arrive
	int dis;
};
vector<route> v[500002];
vector<route> tem[500002];
int a[500002];//from transition to exit
int c,n,m,d,q,k,minv=1e9,x,y;
bool flag[500002];
void p(int cur,int sum)
{
	if(cur==y)
	{
		minv=min(minv,sum);
		return ;
	}
	int size=v[cur].size()-1;
	for(int i=0;i<=size;i++)
	{
		flag[cur]=1;
		if(flag[v[cur][i].plat]==0)p(v[cur][i].plat,sum+v[cur][i].dis);
		
	}
	flag[cur]=0;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int l=0;l<=k-1;l++)
		{
			route tem1;
			cin>>tem1.plat>>tem1.dis;
			tem[i].push_back(tem1);
		}
		for(int l=0;l<=k-1;l++)
		{
			route tem2;
			for(int j=0;j<=k-1;j++)
			{
				bool bbb=0;
				if(l==j)continue;
				tem2.plat=tem[i][j].plat;
				tem2.dis=tem[i][l].dis+tem[i][j].dis;
				int size=v[tem[i][l].plat].size()-1;
				for(int j=0;j<=size;j++)
				{
					if(v[tem[i][l].plat][j].plat==tem2.plat)
					{
						v[tem[i][l].plat][j].dis=min(v[tem[i][l].plat][j].dis,tem2.dis);
						bbb=1;
					}
				}
				if(bbb==0)v[tem[i][l].plat].push_back(tem2);
			}
		}		
	}

	/*int cc=v[2].size()-1;
	//cout<<cc;
	for(int i=0;i<=cc;i++)
		cout<<v[2][i].plat<<" ";*/
		
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		p(x,0);
		cout<<minv+a[x]+a[y]<<endl;
		minv=1e9;
	}
	return 0;
}
