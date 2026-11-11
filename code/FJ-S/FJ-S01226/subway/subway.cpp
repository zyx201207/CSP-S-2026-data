#include<bits/stdc++.h>
using namespace std;
struct node{
	long long n,t,w;
}tuo[500005];
long long w[500005],hard[500005],cnt=1;
void add(long long u,long long v,long long x){
	tuo[cnt].w=x;
	tuo[cnt].t=v;
	tuo[cnt].n=hard[u];
	hard[u]=cnt++;
}
int ssd;
long long n,m,d,q,x,lx,y,ly,k,to,la;
long long minn=999999999;
void dfs(long long x,long long sum,int g){
	if(x==to){
		minn=min(minn,sum)+tuo[x].w;
		return ;
	}
	for(int i=hard[x];i;i=tuo[i].n){
		int v=tuo[i].t;
		if(v==999999999){
			continue;
		}
		if(g!=i){
			dfs(v,sum+tuo[i].w+tuo[v].w,i);
		}else{
			dfs(v,sum+tuo[i].w,g);
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ssd>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	
	for(int ii=1;ii<=n;ii++){
		cin>>k;
		cin>>lx>>ly;
		for(int i=2;i<=k;i++){
			cin>>x>>y;
			add(lx,x,ly);
			cout<<lx<<" "<<x<<endl;
			lx=x;
			ly=y;
		}
		add(lx,0,ly);
	}
	for(int i=1;i<=q;i++){
		cin>>la>>to;
		dfs(la,0,1);
		cout<<minn+w[la]+w[to]<<endl;
	}
	return 0;
}
