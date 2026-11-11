#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=5e3+5;
struct ff{
	int v,next;
}g[N*N];
struct str{
	int u,dis;
	bool operator < (const str& b) const{
		return dis>b.dis;
	}
};
int c,T,n,d,a[N],tot,head[N],ans,dis[N],cnt[N];
void init(){
	tot=0;
	ans=0;
	memset(head,0,sizeof head);
	memset(g,0,sizeof g);
} 
void add(int u,int v){
	g[++tot]={v,head[u]};
	head[u]=tot;
}
int work(int l,int r){
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	priority_queue<str> q;
	q.push({l,0});
	cnt[l]=1;
	dis[l]=0;
	while(!q.empty()){
		str tmp=q.top();
		q.pop();
		int u=tmp.u,d=tmp.dis;
		for(int i=head[u];i;i=g[i].next){
			int v=g[i].v;
			if(v>r) continue;
			if(dis[v]==dis[u]+1){
				cnt[v]++;
			}
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}
		}
	}
//	cout<<l<<" "<<r<<" "<<dis[r]<<" "<<cnt[r]<<'\n';
	return cnt[r];
}
void solve(){
	init();
	cin>>n>>d;
	if(n>5000){
		cout<<0;
		return ;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=lower_bound(a+1,a+i+1,a[i]-d)-a;
		for(int j=tmp;j<i;j++){
			add(j,i);
//			cout<<j<<" "<<i<<endl;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=2;j<=n;j++){
			int tmp=work(i,j);
			if(tmp==2){
				ans++;
				continue;
			}
			if(tmp>2) break;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
