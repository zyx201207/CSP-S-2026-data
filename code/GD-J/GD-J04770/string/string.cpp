#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005;
ll a[N];
string c[N];
int main(){
	ll n,nn=0;
	bool f=0;
	string xd;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		nn+=a[i];
		if(i==1)xd=c[i];
		else{
			if(xd!=c[i])f=1;
		}
	}
	if(f==0){
		cout<<"0";
		return 0; 
	}
	string s,s2;
	nn=nn/2;
	ll m=nn;
	for(ll i=1;i<=n;i++){
		if(a[i]<=m){
        	m-=a[i];
		    for(ll j=1;j<=a[i];j++){
				s+=c[i];
			}  
		}
		else{
			for(ll j=1;j<=m;j++){
				s+=c[i];
			}
			break;
		}
	}
	m=nn;
	for(ll i=1;i<=n;i++){
		if(a[n-i+1]<=m){
        	m-=a[n-i+1];
			for(ll j=1;j<=a[n-i+1];j++){
				s2+=c[n-i+1];
			}              
		}
		else{
			for(ll j=1;j<=m;j++){
				s2+=c[n-i+1];
			}  
			break;
		}
	} 
	ll ans=0;
	for(ll i=0;i<nn;i++){
		if(s[i]!=s2[i])ans++;
	}
	cout<<ans;
	return 0;
}
