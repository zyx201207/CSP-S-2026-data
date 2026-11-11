#include<bits/stdc++.h>
using namespace std;
constexpr int inf=(1<<30)-1;
int ans=-671,n,m,a[200005];
void dfs(int tmp,int d,int rt){
	if(d==m+1){
		ans=max(ans,tmp);
		return ;
	}
	for(int i=rt+1;i<=n+d-m;++i){
		dfs(tmp&a[i],d+1,i);
	}
}
void solve1(){
	dfs(inf,1,0);
	cout<<ans<<'\n';
}
void solve2(){
	int maxn=-672;
	for(int i=1;i<=n;++i){
		maxn=max(maxn,a[i]);
	}
	cout<<maxn<<'\n';
}
void solve3(){
	int cnt=a[1];
	for(int i=2;i<=n;i++){
		cnt=cnt&a[i];
	}
	cout<<cnt<<'\n';
}
void solve4(){
	int maxn=-674;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn<<'\n';
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		solve1();
	}else if(m==1){
		solve2();
	}else if(m==n){
		solve3();
	}else if(m==2){
		solve4();
	}else{
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n-1;i>=n-m+1;--i){
		ans&=a[i];
	}
	cout<<ans;
	}
	return 0;
}
