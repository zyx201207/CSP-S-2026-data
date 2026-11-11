#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6+10;

ll c,t,n,d,x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ll cha=x[n]-x[n-1];
//		cout<<n<<" "<<d<<" "<<cha<<"\n";
		if(d-cha<cha)cout<<0<<"\n";
		else cout<<max(0ll,(n-(d/cha+2)))<<"\n";
	}
	return 0;
}
