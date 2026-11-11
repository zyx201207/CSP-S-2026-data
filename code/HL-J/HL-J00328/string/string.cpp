#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	ll n;
	ll ans=0;
	cin>>n;
	string s,s1;
	while(n--){
		ll m;
		char k;
		cin>>m>>k;
		for(ll i=0;i<m;i++){
			s+=k;
			s1+=k;
		}
	}ll len=s.size();
	reverse(s1.begin(),s1.end());
	if(s==s1){
		cout<<0;
		return 0;
	}
	ll l=0,r=len-1;
	if(len%2==0){
		string p,p1;
		for(ll i=0;i<s.size()/2;i++){
			p+=s[i];
		}for(ll i=0;i<len;i++){
			p1+=s[i];
		}
		reverse(p.begin(),p.end());
		if(p==p1){
			cout<<0;
			return 0;
		}
	}	
	if(len%2!=0){
		while(l!=r){
			if(s[l]!=s[r])ans++;
			l++;
			r--;
		}cout<<ans<<endl;
	}else{
		while(l!=r-1){
			if(s[l]!=s[r])ans++;
			l++;
			r--;
		}if(s[len/2]==s[len/2-1])cout<<ans<<endl;
		else cout<<ans+1;
	}
	return 0;
}