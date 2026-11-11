#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
const int N=505,M=505;
int n,m;
int d,q;
int w[M];
int t[N][M];
int a[N][M];
int k[N];
bool arr[M][N];
bool vis[M];
int Min=0x3f3f3f3f;
void dfs(int s,int e,int v,int step,int x)
{
	if(s==e&&Min>v)
	{
		//cout<<"出来了，答案是："<<v<<endl;
		Min=v;
		return ;
	}

	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(arr[s][i]==1)
			{
			
			 if(vis[a[i][j]]==0)
			 {
			    vis[a[i][j]]=1;
				//cout<<s<<"-->"<<a[i][j]<<" "<<v+t[i][j]<<endl;
		        if(i!=x)
		        {
		        
				dfs(a[i][j],e,v+t[i][j]+w[a[i][j]],step+1,i);
			    }
			    else
			    dfs(a[i][j],e,v+t[i][j],step+1,i);
				vis[a[i][j]]=0;
		    }
		    }
		}
	}
	return ;
}
int main()
{
	int c;
	cin>>c>>n>>m>>d>>q;
	memset(vis,0,sizeof(vis));
	memset(arr,0,sizeof(arr));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			arr[a[i][j]][i]=1;
		}
		
		
	}
	
    
	for(int i=1;i<=q;i++)
	{
		Min=0x3f3f3f3f;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0,0,0);
		Min=Min+w[x]+w[y];
		cout<<Min<<endl;
		
    }
    return 0;
}
