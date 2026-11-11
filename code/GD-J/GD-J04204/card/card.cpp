#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=3e5+10;
int n, m, a[500005], c[300005], l[500005], ans[300005];
bool vis[500005];
void solve(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			vis[j]=1;
			l[j]=0;
		}
		for(int j = 1; j <= m; j++){
			c[j]=0;
		}
		for(int j = i; j <= n; j++){
			l[j]=c[a[j]];
			c[a[j]]=j;
			int ii=l[j];
//			cout<<j<<" "<<l[j]<<'\n';
			while(!vis[ii]){
				ii=l[ii];
				l[j]=l[ii];
				if(ii==0)break;
			}
//			cout<<ii<<'\n';
			if(ii!=j&&ii!=0){
//				cout<<ii<<'\n';
				for(int k = ii; k < j; k++){
					vis[k]=0;
				}
			}
		}
		for(int j = i; j <= n; j++){
			if(vis[j]){
				ans[a[j]]++;
//				cout<<a[j]<<' ';
			}
		}
//		cout<<'\n';
	}
	for(int i = 1; i <= m; i++){
		cout<<ans[i]<<' ';
	}
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
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
