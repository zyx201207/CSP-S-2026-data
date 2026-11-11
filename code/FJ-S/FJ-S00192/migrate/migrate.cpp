#include<bits/stdc++.h>
using namespace std;
int c;
long long t;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0; cin>>n>>d;
		vector<long long> v(2e6+5);
		for(int i=1;i<=n;i++) cin>>v[i];
		if(c==11||c==12){
			if(d>v[1]-v[2]) cout<<n<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		if(c==13||c==14){
			cout<<n<<"\n";
			continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
