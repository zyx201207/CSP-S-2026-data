#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX/5;
int n,k;
vector<int> e[2000005];
int f[2000005];
int find(int x){
//	cout<<114514;
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool b[2000005],h[2000005];
int w[2000005][2],head,tail;
int d[2000005];
void bfs(){
	while(head<tail){
		head++; int x=w[head][0],z=w[head][1];
		for(int y:e[x]){
			if(d[y]>z+1){
				d[y]=z+1;
				w[++tail][0]=y; w[tail][1]=z+1;
			}
		}
//		cout<<114514;
	}
}
int ans;
void dg(int x,int s){
	if(s>k) return;
	if(x==n){
		if(s<k) return;
		head=0,tail=0;
		for(int i=1;i<=n;i++) d[i]=inf;
		for(int i=1;i<=n;i++){
			if(b[i]) f[i]=i;
			else f[i]=0;
			h[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(b[i]==0) continue;
			for(int y:e[i]){
				if(b[y]==0) continue;
				f[find(y)]=find(i);
			}
			d[i]=0;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0) continue;
			if(h[find(i)]==0) h[find(i)]=1,cnt++;
			if(cnt>2) return;
			w[++tail][0]=i; w[tail][1]=0;
		}
		bfs();
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,d[i]);
		ans=min(ans,res);
//		cout<<114514;
		return;
	}
	b[x+1]=1; dg(x+1,s+1);
	b[x+1]=0; dg(x+1,s);
}
void solve(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int x,y; scanf("%lld%lld",&x,&y);
		e[x].push_back(y); e[y].push_back(x);
	}
//	cout<<114514;
	ans=inf;
	dg(0,0);// cout<<114514;
	printf("%lld\n",ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,T; scanf("%lld%lld",&cid,&T);
	while(T--) solve();
	return 0;
}
