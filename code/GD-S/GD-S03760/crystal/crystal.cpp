#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], s[500005];
bool check(int x){
	for(int i = x; i <= n; i++){
		if(a[i]*x-(s[i]-s[i-x])<=m)return true;
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0, r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
} 
/*
估分：100+44+?+15 
我是GD-J04204，迷惑行为大赏能帮我看看GD-J04204的代码有没有加reutrn 0吗 
*/
