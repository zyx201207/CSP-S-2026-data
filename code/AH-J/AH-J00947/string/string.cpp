#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,f,f1,cll;
ll x[200010];
char ch[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i]>>ch[i];
		if(i!=1&&x[i]==x[i-1]) f++;
		else f=0;
		if(i!=1&&ch[i]==ch[i-1]) f1++;
		else f1=0;
	}
	if(f1==(n-1)){
		cout<<0;
		return 0;
	}
	if(f==(n-1)){
		for(ll i=1;i<=n;i++){
			s+=ch[i];
		}
		ll l=0,r=s.size()-1,cnt=0;
		while(l<=r){
			if(s[l]==s[r]){
				l++;
				r--;
			}else{
				l++;
				r--;
				cnt++;
			}
		}
		cout<<cnt*x[1];
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cll+=x[i];
		if(cll>1000000000){
			return 0;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=x[i];j++){
			s+=ch[i];
		}
	}
	ll l=0,r=s.size()-1,cnt=0;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			l++;
			r--;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
