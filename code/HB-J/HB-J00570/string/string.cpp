#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int A=2e5+5;
string s;
ll n,len,a[A];
char c[A],t='A';
int f(){
	ll ans=0;
	for(ll i=1,j=len;i<=len;){
		if(a[i]==a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
				c[i]=c[j];
			}
			i++;
			j--;
			continue;
		}
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				c[j]=c[i];
				j--;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				c[i]=c[j];
				i++;
			}
			continue;
		}
		i--;
		j++;
	}
	return ans;
}
int hw(){
	if(len==1) return 1;
	for(ll i=0,j=len-1;i<len;i++,j--) if(s[i]!=s[j]) return 0;
	return 1;
}
int fr(){
	ll cnt=0;
	for(ll i=0,j=len-1;i<len/2;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
			s[i]=s[j];
		}
	}
	return (ll)(min((len-cnt),cnt));
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=2000){
		for(ll i=1;i<=n;i++){
			ll t;
			string f;
			cin>>t>>f;
			len+=t;
			for(ll i=1;i<=t;i++) s=s+f;
		}
		if(hw()){
			cout<<0;
			return 0;
		}
		cout<<fr();
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll q;
		char w;
		cin>>q>>w;
		if(w==t){
			c[len]=w;
			a[len]+=q;
		}
		else{
			t=w;
			a[++len]=q;
			c[len]=w;
		}
	}
	if(len==1){
		cout<<0;
		return 0;
	}
	cout<<f();
	return 0;
}
