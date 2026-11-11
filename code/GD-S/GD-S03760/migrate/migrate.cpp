#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n, d, a[2000005], ans=0;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+2; j <= n; j++){
			while(a[j]-a[i]<=d)j++;
			int sum=0;
			for(int k = i+1; k < j; k++){
				if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
					sum++;
				}
				if(sum>2)break;
			}
			if(sum==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
	cin>>c>>_;
	while(_--){
		solve();
	}
	return 0;
} 
/*
估分：100+44+?+15 
我是GD-J04204，迷惑行为大赏能帮我看看GD-J04204的代码有没有加reutrn 0吗 
*/
