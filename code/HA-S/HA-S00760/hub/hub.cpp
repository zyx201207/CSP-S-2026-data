#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,k;
int to[4000006],nxt[4000006],h[2000006],cnt;
void add(int a,int b){
	to[++cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
int rt[10],siz[2000006],ma[2000006],hson[2000006],fa[2000006];
void getrt(int u,int f,int num,int x,int p){
	siz[u]=1;
	ma[u]=0;
	for(int i=h[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f)continue;
		if(v==x)continue;
		fa[v]=u;
		getrt(v,u,num,x,p);
		siz[u]+=siz[v];
		if(siz[v]>ma[u]){
			hson[u]=v;
			ma[u]=siz[v];
		}
	}
	ma[u]=max(ma[u],num-siz[u]);
	//cout<<ma[u]<<' '<<ma[rt[p]]<<"\n";
	if(ma[u]<ma[rt[p]]){
		rt[p]=u;
	}
}
int dis[2000006];
void init(){
	memset(to,0,sizeof to);
	memset(nxt,0,sizeof nxt);
	memset(h,0,sizeof h);
	memset(siz,0,sizeof siz);
	memset(fa,0,sizeof fa);
	memset(hson,0,sizeof hson);
	memset(rt,0,sizeof rt);
	memset(dis,0,sizeof dis);
	memset(ma,0,sizeof ma);
	ma[0]=1e9;
	cnt=0;
}
void solve(){
	init();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	//cout<<rt[1]<<"\n";
	getrt(1,0,n,0,1);
	if(rt[1]==1){
		int l=hson[1];
		getrt(1,0,n-siz[l],l,2);
		getrt(l,1,siz[l],0,3);
	}
	else{
		getrt(1,0,n-siz[rt[1]],rt[1],2);
		getrt(rt[1],fa[rt[1]],siz[rt[1]],0,3);
	}
	int ans=0;
	queue<int>q;
	q.push(rt[2]);
	q.push(rt[3]);
	dis[rt[2]]=1;
	dis[rt[3]]=1;
	//cout<<rt[2]<<" "<<rt[3]<<"\n";
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(!dis[v]){
				dis[v]=dis[u]+1;
				ans=max(ans,dis[v]);
				q.push(v);
			}
		}
	}
	cout<<ans-1<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
lougu:???
最后15min，力竭了 
T4部分分，调不出来 
希望能一等
rp++ 
想上电势 
*/
