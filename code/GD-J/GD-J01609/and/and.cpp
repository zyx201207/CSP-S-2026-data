#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=2*1e5+10;
constexpr ll INF=1e18;
int n,m;
bool vis[N];
vector<ll> a;
ll ans=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int now,int cnt){
	if(cnt>m) return;
	if(now==n+1){
		if(cnt!=m) return;
		ll sum=0; int cho=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				if(!cho) sum=a[i],cho++;
				else sum&=a[i];
			}
		}
		ans=max(ans,sum);
		return;
	}
	vis[now]=1;
	dfs(now+1,cnt+1);
	vis[now]=0;
	dfs(now+1,cnt);
}
void solve1(){
	dfs(1,0);
	cout<<ans;
}
void solve2(){
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
}
void solve3(){
	ll c=0;
	for(int i=1;i<=n;i++){
		if(c==0) ans=a[i],c++;
		else ans&=a[i];
	}
	cout<<ans;
}
void solve4(){
	ll sum=0,c=0;
	for(int i=1;i<=n;i++){
		sum=a[i];
		for(int j=i+1;j<=n;j++){
			ans=max(ans,(sum&a[j]));
		}
	}
	cout<<ans;
}
void solve5(){
	ll sum=0,c=0;
	for(int i=1;i<=m;i++){
		if(c==0) sum=a[i],c++;
		else sum&=a[i];
	}
	cout<<sum;
}
void solve(){
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),cmp);
	if(n<=20) solve1();
	else if(n<=2000){
		if(m==1) solve2();
		else if(m==n) solve3();
		else if(m==2) solve4();
	}else{
		solve5();
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}

