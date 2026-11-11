#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll n,d,a[N],s[N],ans;
void solve(){
	int AA=0;
	cin>>n>>d;
	int tt=n-3;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=2)AA=a[i]-a[i-1];
		else if(a[i]-a[i-1]!=AA)AA=INT_MAX;
	}
	if(AA!=INT_MAX){
		if(AA>d)cout<<0<<endl;
		else {
			ll t=1;
			for(int i=5;i<=n;i++){
				t=t*2+1;
			} 
			cout<<t<<endl;
		}
		return; 
	}
	if(a[n]-a[1]<=10*d){
		ll t=1;
		for(int i=5;i<=n;i++){
			t=t*2+1;
		} 
		cout<<t<<endl;
		return;
	}
	cout<<tt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
