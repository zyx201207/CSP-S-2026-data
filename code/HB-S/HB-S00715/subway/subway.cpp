#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
using ll=long long;
const int M=5e5+3,K=5e5+3,N=(5e5+2e3),Q=1e5+3;
const ll MAXX=(1LL<<62)-1+(1LL<<62);

struct node{int id;ll val;};
struct task{int st,en;} a[Q];
bool operator > (const node& one,const node& two){return one.val>two.val;}
bool cmp(const task& one,const task& two){return one.st<two.st;}
vector<node> to[N];//zhanting and xianlu,cundian

int c,n,m,d,q,k;
ll w[M],dist[N];
bool vis[N];

int main()
{
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];//zhanting-chuzhankou
    for(int i=1;i<=n;i++)//xianlu->node_id:K+i
    {
        cin>>k;
        for(int j=1;j<=k;j++)//zhantai
        {
            int x;ll t;node no;
            cin>>x>>t;
            no.id=x,no.val=t;
            to[K+i].push_back(no);
            no.id=K+i;
            to[x].push_back(no);//jiabian
        }
    }
/*    for(int i=0;i<N;i++)
	{
		if(to[i].size())
		{
			cout<<i<<'\n';
			for(node no:to[i])
				cout<<no.id<<' '<<no.val<<'\n';
		}
	}*/
    for(int i=0;i<q;i++)
        cin>>a[i].st>>a[i].en;
        
    priority_queue< node,vector<node>,greater<node> > qheap;
    sort(a,a+q,cmp);
    for(int i=0;i<q;i++)
    {
        int s=a[i].st,t=a[i].en;
        if (i==0|| (i>0&&a[i].st!=a[i-1].st) )
        {
            node no;
            fill(vis,vis+N,false);
            fill(dist,dist+N,MAXX);
            dist[s]=0;
            no.id=s,no.val=0;
            qheap.push(no);
            while(!qheap.empty())
            {
                node f=qheap.top();qheap.pop();
                if (vis[f.id])
                    continue;
                vis[f.id]=1;
                for(const node& x:to[f.id])
                {
                    if (dist[x.id]>dist[f.id]+x.val)
                    {
                        dist[x.id]=dist[f.id]+x.val;
                        no.id=x.id;no.val=dist[x.id];
                        qheap.push(no);
                    }
                }
            }//dijkstra
        };
        long long output=dist[t]+w[s]+w[t];
        cout<< output <<'\n';
    }
    return 0;
}
