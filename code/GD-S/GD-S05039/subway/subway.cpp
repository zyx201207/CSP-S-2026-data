#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],x,y,t[M][N];
ll tt[N][N];
int linshi[25];ll ans=0;
// tt 两两线路间的最短时间  
vector<int> che[M];//该站有哪些线 
vector<int> xian[N];//xian 该线与哪些xian相连
bool use[N];
bool OPT=0;
void dfs(int to,ll time)//现在到哪个线 
{
//	if(time!=t[x][che[x][0]])
//	{
//		cout<<to<<' ';
//		return 1;
//	}
	
	for(int i=0;i<che[y].size();i++)
	{
		if(che[y][i]==to)
		{
			ans=min(ans,time+t[y][to]);
//			return ;
		}
	}
	
	for(int i=0;i<xian[to].size();i++)
	{
		if(use[xian[to][i]])continue;
//		cout<<"ok";return 1;
		use[xian[to][i]]=1;
		dfs(xian[to][i],time+tt[to][xian[to][i]]);
//		return;
		use[xian[to][i]]=0;
		
	}
	return ;
}
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
// n 地铁线路数、
//m 地铁站数d每个地铁站最多被几条线路经过，q以及出行计划数
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int q1,q2;
			cin>>q1>>q2;
			che[q1].push_back(i);//该站点的车 
			t[q1][i]=q2;//该站点到车的时间 
		}
	}
	
	memset(tt,0x3f3f3f3f,sizeof tt); 
	for(int i=1;i<=m;i++)//站 。求车与车间的最短时间 
	{
		if(che[i].size()<=1)continue;
		for(int j=0;j<che[i].size();j++)
		{
			linshi[j]=che[i][j];//有哪些车 
		}
		for(int j=0;j<che[j].size()-1;j++)
		{
			for(int k=j+1;k<=che[i].size()-1;k++)
			{
				int a1=linshi[j],a2=linshi[k];//两辆车 
				ll qqq=t[i][a1]+t[i][a2];
				tt[a1][a2]=min(tt[a1][a2],qqq);
				tt[a2][a1]=t[a1][a2]; //站与站的时间
				bool opt=0;
				if(xian[a1].size())
				{
					for(int p=0;p<xian[a1].size();p++)
					{
						if(xian[a1][p]==a2)
						{
							opt=1;
							break;
						}
					}
				}
				if(opt==0)
				{
					xian[a1].push_back(a2);
					xian[a2].push_back(a1);
				}
				
				
			}
		}
	}
	
//	for(int i=1;i<n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			cout<<tt[i][j]<<'\n';
//		}
//	}
//	return 0;
	
	for(int i=1;i<=q;i++)
	{
		memset(use,0,sizeof use);
		ans=0x7f7f7f7f7f7f7f7f;
		cin>>x>>y;
		if(x>y)swap(x,y);
		for(int i=0;i<che[x].size();i++)
		{
			use[che[x][i]]=1;
			dfs(che[x][i],t[x][che[x][i]]);
//			return 0;
			use[che[x][i]]=0;
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	
	return 0;
}




