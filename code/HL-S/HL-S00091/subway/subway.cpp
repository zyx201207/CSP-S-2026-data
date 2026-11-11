#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=2e5+10 ;
int w[N];
int k[N];
int a[N][M];
int book[N][M]; 
int t[N][M];
int c;
	int n;
	int m; 
	int d;
	int q;
	int dt[N][M];
int rx,ry;
int min_n=0x3f3f3f3f;
void dfs(int j,int i,int ans)
{
	for(int kk=1;kk<=k[i];kk++)
	{
		if(kk==ry)
		{
			min_n=min(min_n,ans);
			return;
		}
		if(book[a[i][kk]][i]==0)
		{
			book[a[i][kk]][i]=1;
			dfs(kk,a[i][kk],ans+t[i][kk]); 
		}
		else if(book[a[i][kk]][i]==0)
		{
			book[a[i][kk]][i]=1;
			dfs(kk,a[i][kk],ans+t[i][kk]); 
		}
		else if(book[a[i][kk]][i]==0)
		{
			book[a[i][kk]][i]=1;
			dfs(kk,a[i][kk],ans+t[i][kk]); 
		}
		else if(book[a[i][kk]][i]==0)
		{
			book[a[i][kk]][i]=1;
			dfs(kk,a[i][kk],ans+t[i][kk]); 
		}
		else if(book[a[i][kk]][i]==0)
		{
			book[a[i][kk]][i]=1;
			int popopossss;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			dt[a[i][j]][i]=1; 
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>rx>>ry;
		for(int j=1;j<=n;j++)
		{
			dfs(rx,j,0);
		}
		cout<<min_n<<endl;
	}
	return 0;
}
