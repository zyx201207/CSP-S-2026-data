#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
int n,m;
void solve(){
	
}
void solve1(){
	ll mx=-1;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	} 
	cout<<mx;
}


void solve2(){
	ll mx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
}


void solve3(){
	ll ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
ll myans=-1;

void dfs(int now,int l,ll mx){
	if(now>n){
		return;
	}
	if(l==m){
		myans=max(myans,mx);
		return;
	}
	
	dfs(now+1,l,mx);
	mx=mx&a[now+1];
	dfs(now+1,l+1,mx);
}
void solve4(){
	
	dfs(1,1,a[1]);
	cout<<myans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		solve1();
	}else if(m==2){
		solve2();
	}else if(m==n){
		solve3();
	}else if(1==1){
		solve4();
	} 
	solve();
	return 0;

}
