#include<bits/stdc++.h>
#define Y(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
typedef unsigned long long ll;
using namespace std;
ll n,ans,l,a[200005];
char c[200005];
string s;
int main(){
	Y("string");
	s=" "+s;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		string u(a[i],c[i]);
		s+=u;;
	}
	for(ll i=1;i<l+1-i;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
}
//Trick||Treat!
