#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll n,a;
ll ans=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;
	for(ll i=1;i<=n;i++){
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s+=c;
		}
	}
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	ll len=s.length();
	for(ll i=0;i<=(len+1)/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
			s[len-i-1]=s[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
