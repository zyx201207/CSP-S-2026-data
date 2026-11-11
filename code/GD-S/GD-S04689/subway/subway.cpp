#include<bits/stdc++.h>
using namespace std;
const signed N=5e5+10;
#define int long long 
int c,m,n,d,k,a,t,q,w[N],isch[N];
vector<int > st[N];
//vector<pair<int , int > > nst[N];//i号线，第几个站 //上换成，下换成 
vector<pair<int ,int > > li[510];
int ls[N],hc[N],tot,vis[N],fhc[N],smax;
int xian[510][510];
//void dij(int s)
//{
//	priority_queue<pair<int,int> > q;
//	q.push({0,s});
//	vis[s]=0;
//	while(!q.empty())
//	{
//		pair<int,int > now=q.top(); q.pop();
//		for(int i=0;i<edge[now.second].size();i++)
//		{
//			pair<int ,int > to=edge[now.second][i];
//			if(vis[to.first]){
//				continue;
//			}
//			vis[to.first]=1;
//			if(d[now.second]++ < d[to])
//			{
//				d[to]=d[now.second] + 1;
//				q.push({d[now.second]+1,to});
//			}
//		}
//	}
//}

signed main()
{
	ios::sync_with_stdio(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
 	cin>>c>>n>>m>>d>>q;
 	
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=n;j++)
				xian[i][j]=1e4;
		xian[i][i]=0;
	}
	
    for(int i=1;i<=m;i++)
    	cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>k; 
    	for(int j=1;j<=k;j++){
    		cin>>a>>t;
    		li[i].push_back({a,t});
    		st[a].push_back(i);
    		if(st[a].size()>1) {
    			for(int k=0;k<st[a].size()-1;k++) xian[i][st[a][k]]=1;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				xian[j][k]=min(xian[j][i]+xian[i][k],xian[j][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			xian[i][j]=min(xian[i][j],xian[j][i]);xian[j][i]=min(xian[i][j],xian[j][i]);
		}
	}
	while(q--)
	{
		int ans=1e14;
		cin>>m>>n;
		for(int i=0;i<st[m].size();i++)
		{
			for(int j=0;j<st[n].size();j++)
			{
				//cout<<st[n][j]<<" "<<st[m][i]<<endl;
				ans=min(xian[st[m][i]][st[n][j]],ans);
			}
		}
		cout<<ans*2*t+w[m]+w[n]<<endl; 
	}
	return 0; 
}
/*

	
   
	for(int i=1;i<=n;i++)
	{
		int lss=-1,nes=-1;
		for(int j=0;j<li[i].size();j++)
		{
			pair<int,int > now=li[i][j];
			if(st[now.first].size()> 1) {
				hc[now.first]==0?hc[now.first]==++tot:hc[now.first]=hc[now.first];
				fhc[tot]==now.first;
				nst[now.first].push_back({i,j});
				lss=now.first;
				cutli[i].push_back(lss);
			}
			else
			{
				ls[now.first]=lss;
			}
		}
		for(int j=li[i].size()-1;j>=0;j--)
		{
			pair<int,int > now=li[i][j];
			if(st[now.first].size()> 1) {
				//nst[now.first].push_back({i,j});
				nes=now.first;
			}
			else
			{
				nst[now.first].push_back({ls[now.first],nes});
				edge[nes].push_back({ls[now.first],i});
				edge[ls[now.first]].push_back({nes,i});
			}
		}
	}
	for(int i=1;i<=tot;i++){
		dij(i);
	}
	while(q--)
	{
		int ans=1e16;
		cin>>m>>n;
		if(!hc[m] && !hc[n])
		{
			if()
		}
		cout<<ans[n][m]+w[m]+w[n]<<endl;
	}
*/
