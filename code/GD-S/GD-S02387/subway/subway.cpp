#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10,maxm=5e6+10;
int b[maxm];
int ne[maxm],head[maxn],cnt,to[maxm],w[maxm];
int dist[maxn];
void add(int u,int v,int ww)
{
	ne[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	w[cnt]=ww;
}
priority_queue<pair<int,int> >q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qu;
	cin>>c>>n>>m>>d>>qu; 
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
      int k;cin>>k;
      while(k--)
      {
        int x,t;cin>>x>>t; 
        add(2*m+i,x,t);
        add(x,2*m+i,t);
        add(x,x+m,t);
        add(x+m,x,t); 
	  }
	}
	for(int z=1;z<=qu;z++)
	{
	  for(int i=1;i<=2*m+n;i++) dist[i]=0x3f3f3f3f;
	  int s,e;
	  cin>>s>>e;
	  dist[s]=0;
	  q.push({0,s});
	  while(!q.empty())
	  {
	  	int u=q.top().second;q.pop();
	  	if(u==e) break;
	  	for(int i=head[u];i;i=ne[i])
	  	{
	  	  int v=to[i];
	  	  if(dist[v]>dist[u]+w[i])
	  	  {
	  	    dist[v]=dist[u]+w[i];
	  	    q.push({-dist[v],v});
		  }
		}
	  }
	  cout<<dist[e]+b[s]+b[e]<<endl;
	}
	return 0;
}
/*
 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3*/
 /*
  0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
