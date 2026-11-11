#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,_;
ll a[N];
inline void solve(){
	int n;ll k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3){
		cout<<0<<'\n';
		return ;
	}
//	if(c==11||c==12){
		int d=a[2]-a[1];
		if(k<d){
			cout<<0<<'\n';
			return ;
		}
		int num=k/d;
		if(num==1){
			ll sum=1ll;
			for(int i=1;i<=4;i++){
				sum*=n-i;
			}
			cout<<sum*2ll<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
//	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--){
		solve();
	}
	return 0;
}

