#include<iostream>//是二分答案?还是换根？反正都不会写，找部分分。
#include<algorithm>//突然发现能写拓扑。尝试。 
#include<queue>//拓扑是错解。好消息是小样例通过率应该挺高。可能十几分？
#include<cmath>//不管了，两百分应该够一等了。 
using namespace std;
int c,t,n,k,nt,ind[1000001],x,y,h[1000001],nxt[4000001],cnt,to[4000001],d[1000001];
queue<int>q;
int check()
{
	if(q.size()>2)return INT_MAX;
	return ceil((double)(max(0,nt-k))/(k+1));
}
int slove()
{
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)if(ind[i]==1)q.push(i),d[i]=1;
	int ft=0;
	while(!q.empty())
	{
		x=q.front();q.pop();
		
		if(ft!=d[x])
		{
			int xx=check();
			if(xx!=INT_MAX)return check()+ft;
			ft=d[x];
		}nt--;
		for(int i=h[x];i!=-1;i=nxt[i])
		{
			ind[to[i]]--,ind[x]--;
			if(ind[to[i]]==1)q.push(to[i]),d[to[i]]=d[x]+1;
		}
	}return ft;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;nt=n;
		for(int i=1;i<=n;i++)h[i]=-1,ind[i]=0;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			nxt[++cnt]=h[x],h[x]=cnt,to[cnt]=y;
			nxt[++cnt]=h[y],h[y]=cnt,to[cnt]=x;
			ind[x]++;ind[y]++;
		}
		cout<<slove()<<endl;
	}
	return 0;
}

