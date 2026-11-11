#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,cnt;
string s;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x>>ch;
		for(ll j=1;j<=x;j++){
			s=s+ch;	
		}
	}string s1=s;
	ll l=s.size();
	reverse(s1.begin(),s1.end());
	for(ll i=0;i<l;i++){
		if(s[i]!=s1[i]) cnt++;
	}cout<<cnt/2;
	return 0;
}
