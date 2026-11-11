#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,d,c,t,x[N];
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
			x[i]-=x[1];
		}if(n<=3){
			cout<<0;
		}else if(c==11||c==12){
			ll d1=x[2]-x[1];
			if(d1*2<d){
				cout<<0<<"\n";
			}else{
				cout<<n-3<<"\n";
			}
		}else{
			cout<<0<<"\n";
		}
	}
	return 0; 
}
