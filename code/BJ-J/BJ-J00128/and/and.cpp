#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;	
ll n,m;
ll a[N];
string b[N];
string tobin(ll x){
	string res;
	while(x!=0){
		char cur=x%2+'0';
		res+=cur;
		x/=2;
	}
	return res;
}
ll todig(string s){
	ll res=0;
	ll pow=1;
//	cout<<s<<"\n";
	for(ll i=0;i<s.size();i++){
		res=res+pow*(s[i]-'0');
		pow*=2;
//		cout<<res<<" "<<pow<<" "<<s[i]<<"\n";
	}
	return res;
}
bool cmp(string s1,string s2){
	ll num1=0,num2=0;
	for(ll i=0;i<s1.size();i++){
		if(s1[i]=='1') num1++;
	}
	for(ll i=0;i<s2.size();i++){
		if(s2[i]=='1') num2++;
	}
	if(num1==num2) return s1.size()>s2.size();
	return num1>num2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		b[i]=tobin(a[i]);
	}
	sort(b+1,b+n+1,cmp);
	ll ans=todig(b[1]);
	for(ll i=2;i<=m;i++){
		ans&=todig(b[i]);
	}
	cout<<ans;
	return 0;
}
