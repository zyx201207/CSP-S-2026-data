//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll x[2000005];
ll n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		for(ll i=1;i<=n;++i){
			cin>>x[i];
		}if(x[2]-x[1]>d){
			cout<<0<<'\n';
		}else if((d/(x[2]-x[1]))%2==0){
			cout<<0<<'\n';
		}else{
			cout<<d/(x[2]-x[1])*(n-2)<<'\n';
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
