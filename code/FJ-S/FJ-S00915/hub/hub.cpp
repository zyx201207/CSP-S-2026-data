#include<bits/stdc++.h>
using namespace std;
int fu[25][110000],dep[110000];
int n,k,totalmin=INT_MAX;
vector<int>vv[110000];
int vis[1100];
int getfu(int u,int faa)
{
	fu[0][u]=faa;
	for(int i=1;i<=21;i++)
		fu[i][u]=fu[i-1][fu[i-1][u]];
	//cout<<u<<endl;
	//for(int i=1;i<=21;i++)cout<<fu[i][u]<<' ';
	//cout<<endl;
	dep[u]=dep[faa]+1;
	for(auto i:vv[u])
	{
		if(i!=faa)getfu(i,u);
	}
	return 0;
}
int dis(int u,int v)
{
	int uu=u,vv=v;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(dep[fu[i][u]]>=dep[v])u=fu[i][u];
	}
	for(int i=20;i>=1;i--)
	{
		if(fu[i][u]!=fu[i][v])u=fu[i][u],v=fu[i][v];
	}
	if(u!=v)
	{
		u=fu[0][u];
		v=fu[0][v];
		//if(uu==4 and vv==9)cout<<uu<<" "<<vv<<" "<<u<<" "<<v<<endl;
		return (dep[uu]-dep[u])+(dep[vv]-dep[v]);
	}
	//if(uu==4 and vv==9)cout<<uu<<" "<<vv<<" "<<u<<" "<<v<<endl;
	return (dep[uu]-dep[u])+(dep[vv]-dep[v]);
}
int dfs(vector<int>vvv)
{
	if(vvv.size()==k+1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int minn=INT_MAX;
			for(auto j:vvv)
			{
				if(j==0)continue;
				minn=min(minn,dis(i,j));
//				if(vvv.size()>3 and vvv[1]==1 and vvv[2]==3 and vvv[3]==9)
//				{
//					cout<<i<<" "<<j<<" dis="<<dis(i,j)<<endl;
//				}
				//cout<<i<<" "<<j<<" "<<dis(i,j)<<endl;
			}
			maxn=max(maxn,minn);
		}
//		cout<<"////////\n";
//		for(auto i:vvv)cout<<i<<' ';
//		cout<<endl;
//		cout<<maxn<<endl;
//		cout<<"////////\n";
		return totalmin=min(totalmin,maxn);
	}
	for(int i=vvv[vvv.size()-1]+1;i<=n;i++)
	{
		vvv.push_back(i);
		memset(vis,0,sizeof vis);
		queue<int>q;
		for(auto j:vvv)vis[j]=-1;
		int cctt=0;
		for(int kkk=1;kkk<=n;kkk++)
		{
			if(vis[kkk]==1 or vis[kkk]==0)continue;
			//cout<<"dangqiandaoda"<<kkk<<endl;
			cctt++;
			//cout<<cctt<<endl;
			if(cctt>2)break;
			q.push(kkk);vis[kkk]=1;
			while(q.size())
			{
				//if(kkk==4)cout<<"hi\n";
				int p=q.front();q.pop();
				for(auto j:vv[p])
				{
					//cout<<"jjj"<<j<<endl;
					if(vis[j]==-1)
					{
						vis[j]=1;
						q.push(j);
					}
				}
			}
		}
		//cout<<"这是一个合法序列\n";
//		cout<<"------\n";
//		for(auto i:vvv)cout<<i<<' ';
//		cout<<endl;
//		cout<<cctt<<endl;
//		cout<<"------\n\n\n";
		if(cctt>2)vvv.pop_back();
		else
		{
			dfs(vvv);
			vvv.pop_back();
		}
	}
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//请开freopen
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		totalmin=INT_MAX;
		for(int i=1;i<=n;i++)vv[i].clear();
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			vv[u].push_back(v);
			vv[v].push_back(u);
		}
		getfu(1,0);
//		for(int i=20;i>=0;i--)
//		{
//			for(int j=1;j<=n;j++)
//				cout<<fu[i][j]<<" \n"[j==n];
//		}
		//continue;
		vector<int>tmp;
		tmp.push_back(0);
		dfs(tmp);
		cout<<totalmin<<endl;
	}	
	
	return 0;
}

