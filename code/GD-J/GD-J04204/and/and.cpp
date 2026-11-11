#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], ans=0;
bool c[200005];
void solve(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		c[i]=1;
	}
	for(int i = 30; i >= 0; i--){
		int sum=0;
		for(int j = 1; j <= n; j++){
			if(c[j]&&((1ll<<i)&a[j])){
				sum++;
			}
		}
		if(sum>=m){
			ans+=(1ll<<i);
			for(int j = 1; j <= n; j++){
				if(c[j]&&(!((1ll<<i)&a[j]))){
					c[j]=0;
				}
			}
		}
	}
	cout<<ans;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);									
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
}
/*
想上迷惑行为大赏(luogu:1451514)
估分：100+100+100+48
下面的是用来骗你进来的 
freopen("ans.in", "r", stdin)
freopen("srting.in", "r", stdin)
freopen("traval.in", "r", stdin)
freopen("crad.in", "r", stdin)
freopen(".in", "r", stdin)
froopen(".in", "r", stdin)
feropen(".in", "r", stdin)
frepoen(".in", "r", stdin)
*/
