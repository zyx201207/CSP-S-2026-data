#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N=500,M=5e5+10;
int c,n,m,d,q,x,y,ans,lst,w[M],k[N],a[N][M],t[N][M];
vector<int> e[N],l[N];
void dfs(int dx,int line, int sum)
{
	if(dx==y)
		if(sum<ans)
			ans=sum;
	for(auto i : e[dx])
	{
		for(auto j : l[i])
			if(line==j)
				dfs(i,line,sum);
			else
				dfs(i,j,sum+t[line][j]+t[j][j]);
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		lst=0;
		for(int j=1;j<=k[i];++j)
		{
			cin>>a[i][j]>>t[i][j];
			if(lst != 0)
			{
				e[lst].push_back(j);
				lst=j;
			}
			l[j].push_back(i);
		}
	}
	for(int r=1;r<=q;++r)
	{
		cin>>x>>y;
		for(auto i : l[x])
			dfs(x,i,0);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	cout<<1;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
