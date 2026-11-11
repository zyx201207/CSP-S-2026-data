#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000000005],ans=0;
char ss;
string s,x,y;
int main(){

	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>ss;	
		for(ll j=1;j<=a[i];j++){
			s+=ss;	
		}
	}
	ll len=s.size();
	ll len_h1,len_h2;
	len_h1=len/2;
	if(len%2==0) len_h2=len_h1-1;
	else len_h2=len_h1;
	for(ll i=0;i<len_h1;i++){
		x+=s[i];
		
	}
	for(ll i=len-1;i>len_h2;i--){
		y+=s[i];
		
	}
	for(ll i=0;i<len_h1;i++){
		if(x[i]!=y[i]){
			ans++;
		}
	}
	cout<<ans;

	return 0;
} 
