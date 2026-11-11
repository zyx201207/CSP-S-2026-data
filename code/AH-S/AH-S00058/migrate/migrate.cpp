#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll thi,t,n,d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>thi>>t;
	while(t--){
		ll cnt=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(ll i=1;i<=n-3;i++){
			if(x[i+1]-x[i]==x[i+3]-x[i+2]&&x[i+1]-x[i]<=d&&x[i+3]-x[i+2]<=d&&x[i+3]-x[i]>d){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
