#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],f[10][10],k[505],a,b;
pair<int,int> sub[505][505];
vector<int>place[505];
int ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<505;i++){place[i].push_back(0);}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)
		{
			f[i][j]=10000000;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a>>b;
			sub[i][k[i]]=pair<int,int>(a,b);
			place[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int o=1;o<m;o++)
		{
			for(int j=1;j<place[i].size();j++)
			{
				for(int l=1;l<=k[i];l++)
				{
					f[i][sub[place[i][j]][l].first]=min(f[i][o]+sub[place[i][j]][l].second+sub[i][l].second,f[i][sub[place[i][j]][l].first]);
				}
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		cout<<f[a][b]+w[a]+w[b]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
