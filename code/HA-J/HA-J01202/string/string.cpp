#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
char ch;
ll n,a[200005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>ch;
		for(ll j=1;j<=a[i];j++){
			s+=ch;
		}
	}
	ll len=s.size();
	for(ll i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			++ans;
		}
	}cout<<ans;
	return 0;
}
