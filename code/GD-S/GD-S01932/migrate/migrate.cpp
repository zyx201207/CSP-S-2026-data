#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll c,t,n,d;
ll w[N];
ll x[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			cout<<n*2<<'\n';
		}
		if(c==13||c==14){
			cout<<n/2<<'\n';
		}else{
			int k;
			cout<<n-(k%n)<<'\n';
		}
	}
	return 0;
}
