#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
int w[N],k[N],dis[N];
typedef pair<int,int> pii;
vector<int> p[N],s[N];
vector<int> e2[N];
vector<pii> e[N];
bool v[N];
int tp[310][310][310];
int dijkstra(int st,int ed)
{
//	cout<<endl;
	for(int i=1;i<=m;i++)
	 dis[i]=INF,v[i]=false;
	dis[st]=0;
	for(int i=1;i<=m;i++)
	{
		int pos=1e9,id=0;
		for(int j=1;j<=m;j++)
		 if(pos>dis[j]&&v[j]==false)
		  pos=dis[j],id=j;
//		cout<<pos<<" "<<id<<endl;
		v[id]=true;
		for(pii t:e[id])
		{
		 
		 dis[t.first]=min(dis[t.first],dis[id]+t.second);
//		 cout<<dis[t.first]<<" "<<t.second<<endl;	
		} 
		
	}
	return w[st]+w[ed]+dis[ed];
}
void query1()
{
	for(int i=1;i<=n;i++)
	 for(int j=0;j<k[i];j++)
	 	for(int w=j+1;w<k[i];w++)
	 	{
	 		int pos1=p[i][j],pos2=p[i][w];
	 		int cnt1=s[i][j],cnt2=s[i][w];
	 		e[pos1].push_back({pos2,cnt1+cnt2});
	 		e[pos2].push_back({pos1,cnt1+cnt2});
		}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<endl;
//		for(pii j:e[i])
//		 cout<<j.first<<" "<<j.second<<endl;
//	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)<<endl;
	}
	return;
}
//void query2()
//{
//	for(int i=1;i<=n;i++)
//	 for(int j=0;j<k[i];j++)
//	 	for(int w=j+1;w<k[i];w++)
//	 	{
//	 		int pos1=p[i][j],pos2=p[i][w];
//	 		int cnt1=s[i][j],cnt2=s[i][w];
//	 		e[pos1].push_back({pos2,cnt1+cnt2});
//	 		e[pos2].push_back({pos1,cnt1+cnt2});
//		}
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	 cin>>w[i];
	bool pd=true,pd2=true;
//	ll pos=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2)
		 pd=false;
		for(int j=1;j<=k[i];j++)
		{
			int x,y;cin>>x>>y;
//			if(pos==0)
//			 pos=y;
//			if(y!=pos)
//			 pd2=false;
			p[i].push_back(x);
			s[i].push_back(y);
		}
	}
//	if(pd1==true)
//	 query2();
	query1();
	return 0;
}
/*
0 3 4 20 1
1 2 3 4
2 1 3 2 4
2 1 4 3 4
2 3 2 4 2
1 4

*/
