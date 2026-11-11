#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
long long T,c,n,d,x[N],an;
void solve(){
	cin>>n>>d;
	if(n<=3){
		cout<<0<<'\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		cin>>x[i];
		
	}
	if(abs(x[n]-x[1])<=d){
		cout<<0<<'\n';
		return ;
	}
	cout<<(n-1)/2<<'\n';
	
	
}

signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
//I AK IOI
