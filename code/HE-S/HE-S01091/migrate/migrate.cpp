#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
using namespace std;
const int N=2e6+10;
int n;
ll x[N];
ull d;
ll k;
ull ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		k=0; d=0; 
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11 || c==12){
			if(x[2]-x[1] > d) {
				cout<<0<<'\n';
				continue;
			}
			ll len=x[2]-x[1];
			ll cnt=d/len;
			for(ll i=n-1;i>=cnt;i--){
				k++; 
				if(i%cnt==0) continue;
				ans+=k;
			}
			cout<<ans<<'\n';
		}
	}
	
	
	
	return 0;
}
