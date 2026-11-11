#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll n;
char a[1000000009];
ll cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	ll i=1;
	for ( int j = 1; j <= n; j++){
		ll t;char x;
		cin>>t>>x;
		for(ll z=i;z<=i+t-1&&z;z++) a[z]=x;
		i+=t;
	}
	ll l=i-1;
	for(i =1;i<=l;i++) cout<<a[i];
	
	 i=1;
	 ll j=l;
	while(i<=j){
		if(a[i]!=a[j]) cnt++;
		i++;
		j--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
