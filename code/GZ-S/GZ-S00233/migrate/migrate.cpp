//GZ-S00233 遵义市第四中学 毛俊程 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e6+5;
int c,T,n;
ll x[MAXN],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll sum=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			sum+=x[i];
		}
		if((x[1]+x[n])*n/2!=sum){
			cout<<"0"<<'\n';
			continue;
		}
		if(d!=2){
			cout<<"0"<<'\n';
			continue;
		}
		cout<<n-3<<'\n';
	}
	return 0;
}

