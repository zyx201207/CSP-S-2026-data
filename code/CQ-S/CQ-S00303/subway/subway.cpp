#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
struct tree{
	vector<int> to_zt;
	vector<int> to_lx;
	vector<int> to[N];  
};
int c,n,m,d,q;
long long minn=M*N;
int a[M],t[M];	
bool vis[M];
tree trees[20005];
void dfs(int,int,long long,int);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		trees[i].to_zt.push_back(w);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++)
		{	
			trees[a[j]].to_lx.push_back(t[j]);
			trees[a[j]].to_zt.push_back(t[j]);
			for(int x=1;x<=k;x++)
			{
				if(x!=j) trees[a[j]].to[i].push_back(a[x]);
			}
		}
	}
	/*cout<<"yes"<<endl;
	for(int i=1;i<=m;i++)
	{
		cout<<i<<endl<<"to_lx";
		for(int j=0;j<trees[i].to_lx.size();j++) cout<<trees[i].to_lx[j]<<' '; 
		cout<<endl<<"to_zt";
		for(int j=0;j<trees[i].to_zt.size();j++) cout<<trees[i].to_zt[j]<<' ';
		cout<<endl;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<trees[i].to[j].size();k++)
			{
				//cout<<"yes"<<' '<<i<<' '<<k<<endl;
				cout<<trees[i].to[j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<endl;*/
	while(q--)
	{
		
		int x,y;
		cin>>x>>y;
		dfs(x,y,0,0);
		cout<<minn<<endl;
		minn=M*N;
	}
}
void dfs(int x,int y,long long ans,int xl)
{
	//cout<<x<<' '<<y<<' '<<ans<<' '<<xl<<endl;
	if(x==y)
	{
		int l=n-xl;
		while(!(trees[x].to_lx[l]==trees[x].to_zt[l]) && l>=1) l--;
		ans=ans+trees[x].to_lx[l]+trees[x].to_zt[0];
		//cout<<"yes"<<l<<' '<<x<<' '<<xl-1<<' '<<trees[x].to_lx[l]<<' '<<trees[x].to_zt[0]<<endl;
		minn=min(minn,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=xl && trees[x].to[i].size()!=0)
		{
			ans+=trees[x].to_zt[xl]+trees[x].to_lx[i-1];
			xl=i;
		}
		for(int j=0;j<trees[x].to[i].size();j++)
		{
			if(vis[trees[x].to[i][j]]==false)
			{
				vis[trees[x].to[i][j]]=true;
				//ans+=trees[trees[x].to[i][j]].to_lx[i-1];
				dfs(trees[x].to[i][j],y,ans,xl);
				//cout<<"·µ»Ø"<<endl;
				vis[trees[x].to[i][j]]=false;
				//ans-=trees[trees[x].to[i][j]].to_lx[i-1];
			}
		}
	}
}
