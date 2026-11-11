#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	string k;
	ll n,f=0,pan=0;
	ll sam=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll s;
		cin>>s;
		char w;
		cin>>w;
		for(ll j=f;j<s+f;j++){
			k[j]=w;
		}
		f+=s;
	}
	for(ll i=0;i<f;i++){

			if(k[i]!=k[f-1-i]){
				pan=1;
				break;

		}
	}
	if(pan==0){
		cout<<"0";
		return 0;
	}
		for(ll i=0;i<f;i++){

			if(k[i]!=k[f-1-i]){
				sam++;
			}

	}
	cout<<sam/2;
}
