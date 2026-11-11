#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define N 2000005
#define M 5005
#define ll long long
#define INF (ll)1e18
#define PII pair<ll, ll>
#define lowbit(x) (x&(-x))

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0; ch=getchar(); }
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return (f?res:-res);
}
int n, c, cnt[M], a[M][M], dis[M], vis[M];
ll d, x[N], ans;
queue<int> q;
void solve1(){
	int i=0;
	for(i=1; i<=n; i++) if(abs(x[i]-x[1])>d) break;
	i--;
	if(i==2||abs(x[3]-x[1])>=2*d) puts("0");
	else printf("%d\n", max(n-(2*(i-1)-1), 0));
}
void bfs(int s){
	for(int i=1; i<=n; i++) dis[i]=(ll)1e9, vis[i]=cnt[i]=0;
	q.push(s), dis[s]=0, cnt[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int y=1; y<=n; y++){
			if(a[x][y]){
				if(dis[y]>dis[x]+1) cnt[y]=cnt[x], dis[y]=dis[x]+1, q.push(y);
				else if(dis[y]==dis[x]+1) cnt[y]+=cnt[x];
			}
		}
	}
}
void solve2(){
	ans=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			a[i][j]=0;
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d) a[i][j]=1;
		}
	}
	for(int s=1; s<=n; s++){
		bfs(s);
		for(int x=1; x<=n; x++){
//			cout<<cnt[x]<<' ';
			if(cnt[x]==2) ans++;
		}
//		puts("");
	}
	printf("%lld\n", ans>>1);
}
void solve(){
	n=rd(), d=rd();
	for(int i=1; i<=n; i++) x[i]=rd();
	if(c==11||c==12) solve1();
	else solve2();
//	solve2();
}
int main(){
//	system("fc migrate.out migrate3.ans");
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c=rd();
	for(int tt=rd(); tt--; solve());

	return 0;
}
/*

*/

