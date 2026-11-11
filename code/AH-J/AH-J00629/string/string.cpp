#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
    string s="";
		for(ll i=1;i<=n;i++){
		    ll a;
		    char c;
		    scanf("%lld %c",&a,&c);
		    for(ll j=1;j<=a;j++){
			    s+=c;
		     }
	    }
	    ll len=s.size();
	    ll cnt=0;
	    for(ll i=0;i<len;i++){
		    if(s[i]!=s[s.size()-i-1]){
			   s[i]=s[s.size()-i-1];
			   cnt++;
		    }
	     }
	    cout<<cnt;
	return 0;
}
