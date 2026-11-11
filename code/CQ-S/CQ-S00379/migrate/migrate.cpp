/*
AFO了，回望我信竞的三年，不知道这次的发挥到底是好是坏
最好就是100+100+0+0我也没啥好说的，大学再见吧。 
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
int a[maxn],flag[maxn];
int T,c;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==0)cout<<1<<endl;
	else cout<<0<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}


