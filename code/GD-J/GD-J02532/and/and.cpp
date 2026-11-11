#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
ll n,m,a[maxn];
bool vis[maxn];
ll ans=0;
bool have0=false;
void dfs1(ll s,ll sum){//枚举m个数并计算按位与 
	if(s>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(s==1){
				dfs1(s+1,a[i]);
			}
			else{
				dfs1(s+1,sum&a[i]);
			}
			vis[i]=false;
		}
	}
}
void solve1(){//n<=2000,暴力 
	dfs1(1,1);
	cout<<ans;
}
void solve2(){//特殊性质B：排序 
	sort(a+1,a+n+1,greater<ll>());
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			have0=true;
		}
	}
	if(n<=2000||m<=2){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
