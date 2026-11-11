#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e6+5;
int c,T,n;
LL d,x[N];
int vis[N],cnt[N];
bool bfs(int s,int e){
	queue<int> q;
	for(int i=s;i<=e;i++){
		vis[i] = 0;
		cnt[i] = 0;
	}
	q.push(s);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now==e){
			if(cnt[e]>=3) break;
			continue;
		}
		for(int i=now+1;i<=e&&x[i]-x[now]<=d;i++){
			if(vis[now]<vis[i]||vis[i]==0){
				vis[i] = vis[now]+1;
				cnt[i]++;
				q.push(i);
			}
		}
	}
	if(cnt[e]==2) return true;
	else return false;
}
void solve1(){
	LL ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)) ans++;
			}
		}
	cout<<ans<<'\n';
}
void solve2(){
	LL y = x[2]-x[1];
	LL cnt = d/y;
	if(cnt<=1){
		cout<<0<<'\n';
	}else cout<<max(n-cnt-cnt+1,0ll)<<'\n';
}
void solve3(){
	LL ans = 0;
	for(int i=1;i<=n;i++){
		bfs(i,n);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool flag = 0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=2&&x[i]-x[i-1]!=x[2]-x[1]) flag = 1;
		}
		if(n<=5000){
			solve3();
		}else if(!flag){
			solve2();
		}else{
			solve3();
		}
	}
	return 0;
}
