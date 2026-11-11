#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e6+10;
int a[N],n,T,c,rx[N],d,lx[N];
int tot,to[N],nxt[N],head[N],cnt[N],dis[N];
void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int ask(int x){
	int l=x,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(a[mid]-a[x]<=d){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}
const int INF=1e18;
typedef pair<int,int> PII;
int vis[N];
void dijk(int s){
	for(int i=0;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
		cnt[i]=0;
	}
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII > > q;
	q.push({0,s});
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				cnt[y]=1;
				q.push({dis[y],y});
			}else if(dis[y]==dis[x]+1){
				cnt[y]++;
//				if(s==1)cout<<y<<" "<<cnt[y]<<endl; 
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=tot;i++){
		head[i]=nxt[i]=to[i]=0;
	}
	tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<"XXX";
	for(int i=1;i<=n;i++){
		int R=ask(i);
		rx[i]=R;
		lx[R]=i;
//		cout<<i<<" "<<R<<"\n";
		for(int j=i+1;j<=R;j++){
			add(i,j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		dijk(i);
		for(int j=1;j<=n;j++){
//			cout<<dis[j]<<" ";
			if(cnt[j]==2)ans++;
		}
//		cout<<"\n";
//		cout<<ans<<"\n";
//		for(int j=1;j<=n;j++)cout<<cnt[j]<<" ";
//		cout<<"\n";
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
//	cout<<"XG";
	while(T--){
		solve();
//		tot=0;
	}
	return 0;
}
/*
0 1
10 327
-1000 -673 -346 -128 90 199 308 417 635 962
*/
