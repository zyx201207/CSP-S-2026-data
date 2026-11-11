#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t,n,d;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			ll A=d/(x[2]-x[1]);
			if(A==1||2*A>n){
				cout<<"0\n";
			}
			else{
				cout<<n-(2*A-1)<<"\n";
			}
		}
	}
	return 0;
}
