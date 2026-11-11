#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int> d[2000010];
int vis[2000010];
struct nide{
	int id;
	int rn;
	int shen;
};
int mxi=-1e9;
int mx=-1e9;
int dfs(int w,int ren)
{
	queue<nide >q;
	nide G;
	G.id=w;
	G.rn=ren;
	G.shen=0;
	q.push(G);
	vis[w]=1;
	while(!q.empty())
	{
		nide t=q.front();
		q.pop();
		if(t.rn<=1)
		 continue;
		int fren=floor((t.rn-1)/d[t.id].size())+1;
		int zong=t.rn-1;
		for(int i=0;i<d[t.id].size()&&zong>=0;i++)
		{
			if(vis[d[t.id][i]]==1) continue;
			nide de;
			de.id=d[t.id][i];
			if(zong>=fren)
			{
				zong-=fren;
				de.rn=fren;
			}
			else 
			{
				de.rn=zong;
				zong=0;
			}
			de.shen=t.shen+1;
			if(de.shen>=mx)
			{
				mxi=mx;
				mx=de.shen;
			}
			vis[de.id]=1;
			q.push(de);
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=1e6;i++) 
		{
			while(!d[i].empty()) d[i].pop_back();
		}
		
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			d[u].push_back(v);
			d[v].push_back(u);
		}
		dfs(1,k);
		int ling=0;
		mxi=max(mxi,ling);
		cout<<mx<<endl; 
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
