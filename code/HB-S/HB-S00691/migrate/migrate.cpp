#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void sovle(){
	ll n,d,cc=1;
	cin>>n>>d;
	if(d==1){
		cout<<0<<endl;
	}
	ll a[n+5],b[n+5];
	cin>>a[1];
	for(ll i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]<=d){
			b[i]=a[i]-a[i-1];
			cc++;
		}else{
			break;
		}
	}
	if(cc==3){
		cout<<0<<endl;
	}else if(cc<=d*2){
		cout<<1<<endl;
	}else if(cc>d*2){
		cout<<2<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		sovle();
	}
	return 0;
}
