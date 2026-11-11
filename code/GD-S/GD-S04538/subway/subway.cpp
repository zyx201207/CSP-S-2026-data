#include<bits/stdc++.h>
using namespace std;
int cnt,st[100010],ed[100010],c,u,v,n,m,dd,t,k,num,a[500010],d[510010];
int s[510][500510];
bool vis[510][500510],run[510];
long long w,miku,dis[2000010];
struct arata{
	int b,c,nxt;
}e[1000010];
struct ouka{
	int u;
	long long w;
};
priority_queue<ouka>q;
bool operator<(const ouka a1,const ouka a2){
	return a1.w>a2.w;
}
void cun(int a,int b,int c){
	e[++k].b=b;
	e[k].c=c;
	e[k].nxt=d[a];
	d[a]=k;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>dd>>t;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>v>>w;
			cun(v,m+i,w);
			cun(m+i,v,w);
		}
	}
	for(int i=1;i<=t;i++){
		cin>>st[i]>>ed[i];
		for(int j=d[st[i]];j;j=e[j].nxt){
			s[e[j].b-m][ed[i]]=++cnt;
			run[e[j].b-m]=true;
		}
	}
	for(int p=1;p<=n;p++){
		if(!run[p])continue;
		q.push({m+p,0});
		while(q.size()){
			u=q.top().u;w=q.top().w;
			q.pop();
			if(vis[p][u])continue;
			if(s[p][u])dis[s[p][u]]=w;
			vis[p][u]=true;
			for(int i=d[u];i;i=e[i].nxt){
				q.push({e[i].b,w+e[i].c});
			}
		}
	}
	for(int i=1;i<=t;i++){
		miku=1e16;
		for(int j=d[st[i]];j;j=e[j].nxt){
			miku=min(miku,dis[s[e[j].b-m][ed[i]]]+e[j].c);
		}
		miku=miku+a[st[i]]+a[ed[i]];
		cout<<miku<<"\n";
	}
	return 0;
}
