#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N=500,M=5e5+10;
int c,n,m,d,q,x,y,ans,lst,l[N],w[M],k[N],a[N][M],t[N][M];
vector<int> e[N];
void dfs(int dx,int sum)
{
	if(dx==y)
		if(sum<ans)
			ans=sum;
	for(auto i:l[a[dx]])
	{
		dfs(dx);
	}
	
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
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
			l[j]=i;
		}
	}
	for(int r=1;r<=q;++r)
	{
		cin>>x>>y;
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<"\n";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
