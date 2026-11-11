#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[555555],k,a,t;
vector<int>dtz[555555];
vector<int>zt[555555];
vector<int>lx[555555];
vector<int>sj[555555];
int st,ed;bool arv[555555];
long long ans;bool vv[555555];
void aaa(int u,long long cnt)
{
	if(arv[u]){cout<<888;
	    ans=min(ans,cnt+arv[u]);return;}
	for(int v=0;v<lx[u].size();v++)
	{
		if(u==lx[u][v])continue;
		if(!vv[lx[u][v]])
		{
			
			vv[lx[u][v]]=1;
			aaa(lx[u][v],cnt+sj[u][v]);
			vv[lx[u][v]]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)//Â·Ïß 
	{
		cin>>k;
		for(int j=0;j<k;j++)//Í¾¾¶Õ¾ 
		{
			cin>>a;dtz[a-1].push_back(i);
			cin>>t;zt[a-1].push_back(t);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int u=0;u<dtz[i].size();u++)
		{
			for(int v=0;v<dtz[i].size();v++)
			{
				if(u==v)continue;
				lx[dtz[i][u]].push_back(dtz[i][v]);
				lx[dtz[i][v]].push_back(dtz[i][u]);
				sj[dtz[i][u]].push_back(zt[i][u]+zt[i][v]);
				sj[dtz[i][v]].push_back(zt[i][u]+zt[i][v]);
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>st>>ed;st--;ed--;ans=1e9;memset(arv,0,555555);
		for(int j=0;j<dtz[ed].size();j++)arv[dtz[st][j]]=zt[st][j];
		for(int j=0;j<dtz[st].size();j++)aaa(dtz[st][j],zt[st][j]);
		cout<<ans+w[st]+w[ed]<<'\n';
	}
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
