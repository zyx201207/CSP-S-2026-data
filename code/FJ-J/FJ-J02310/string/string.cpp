#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[1000005]={0};	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,a,b=0,d=0;
	char c;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a>>c;
		for(ll j=i;j<i+a;j++){
			s[i+j]=c-'a';
		    d++;
		}
	}
	for(ll o=0;o<(d+1)/2;o++){
		if(s[o]!=s[d-o-1]) b++;
	}
	cout<<b;
	return 0;
}
