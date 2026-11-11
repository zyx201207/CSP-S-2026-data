#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=2e6+7;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	int c,t;cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			ll n,d;cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			ll k=d/(a[2]-a[1]);
			if(k<=1) cout<<0<<'\n';
			else{
				k=k*2-1;
				cout<<max(0LL,n-k)<<'\n';
			}
		}
	}
	cout<<endl;
	return 0;
}
