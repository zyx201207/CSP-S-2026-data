#include<bits/stdc++.h>
using namespace std;
struct ed{
	long long n,t,w;
}tuo[2000006];
long long hard[2000006],cnt=1,dis[2000006],a[2000006],vs[2000006],vis[2000005];
void add(long long u,long long v,long long x){
	tuo[cnt].w=x;
	tuo[cnt].t=v;
	tuo[cnt].n=hard[u];
	hard[u]=cnt++;
}
struct node{
	long long dis;
	long long pos;
	bool operator<(const node &x)const{
		return x.dis<dis;
	}
};
priority_queue<node>q;
int csd;
long long t;
long long n,d,sum;
void dij(long long s){
	dis[s]=0;
	q.push(node{0,s});
	while(!q.empty()){
		node ty=q.top();
		q.pop();
		long long u=ty.pos,dd=ty.dis;
		if(!vis[u]){
			vis[u]=1;
			for(int i=hard[u];i;i=tuo[i].n){
			long long v=tuo[i].t;
			cout<<v<<endl;
			
			if(dis[v]>=dis[u]+1){
				if(dis[v]==dis[u]+1){
					sum++;
				}
				dis[v]=dis[u]+1;
				q.push(node{dis[v],v});
				
			}
		}
		}
		
	}
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>csd;
	cin>>t;
	while(t--){
		cin>>n>>d;
		cnt=1;
		sum=0;
		for(int i=1;i<=n*2;i++){
			hard[i]=0;
			tuo[i].n=0;
			tuo[i].t=0;
			tuo[i].w=0;
			dis[i]=0;
			vs[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(abs(a[i]-a[j])<=d){
					add(a[i],a[j],1);
					add(a[j],a[i],1);
				}
			}
		}
		dij(n);
		for(int i=1;i<=n;i++){
			cout<<dis[i]<<" ";
		}
		cout<<sum;
	}
	return 0;
}
