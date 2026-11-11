#include<bits/stdc++.h>
using namespace std;
const int MAXn=1e5+5;
#define ll long long
ll n,sum=0;
ll a[MAXn];
string s;
char c[MAXn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	ll L;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]=a[i]+a[i-1];
		for(ll j=a[i-1];j<a[i];j++){
			s[j]=c[i];
		}
	}
	L=a[n];
	for(ll i=0;i<(L+1)/2;i++){
		if(s[i]!=s[L-1-i]){
			s[L+1-i]=s[i];
			sum++;
		}
	}
	printf("%lld",sum);
	return 0;
}

