#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
string a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>c>>a;
		while(c--) s+=a;
	}	
	ll cnt=0;
	string t=s;
	reverse(s.begin(),s.end());
	for(ll i=0;i<s.size()/2;i++){
		if(t[i]!=s[i]) cnt++;
	}	
	cout<<cnt;
	return 0;
} 
