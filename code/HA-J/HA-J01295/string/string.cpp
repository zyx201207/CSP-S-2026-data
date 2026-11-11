#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	vector<char> b(n);
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(b[0]==b[1]){
			cout<<0;
		}
		else{
			if(a[1]<a[0]){
				cout<<a[1];
				return 0;
			}
			else{
				cout<<a[0];
				return 0;
			}
		}
	}
	return 0;
} 
