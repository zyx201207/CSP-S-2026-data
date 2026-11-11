#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,cnt;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		ll x;
		string c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	for(ll i=0,j=s.size()-1;i<s.size(),j>=0;i++,j--){
		if(i>j) break;
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}
