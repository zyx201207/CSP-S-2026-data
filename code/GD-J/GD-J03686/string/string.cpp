#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans,k,s,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	vector<ll>a(n+5,0);
	vector<char>b(n+5);
	for(ll i=0;i<n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
		if(i==0)k=a[i];
		else k=__gcd(k,a[i]);
	}
	vector<ll>c(s/k+5);
	for(ll i=0;i<n;i++){
		for(ll x=0;x<a[i]/k;x++){
			c[j++]=b[i];
		}
	}
	for(ll i=0;i<s/k/2;i++){
		if(c[i]!=c[s/k-1-i])ans+=k;
	}
	cout<<ans;
	return 0;
}

