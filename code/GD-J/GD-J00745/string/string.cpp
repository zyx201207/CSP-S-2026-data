#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+100;
ll n;
string s="";
string c1="",c2=""; 
ll cnt=0;
ll a[N];
char c[N];
bool ok=true;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(ll i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			ok=false;
			break;
		}
	}
	if(ok){
		ll x;
		for(ll i=1;i<=n;i++){
			s+=c[i];
			if(i==n){
				x=a[i];
			} 
		}
		ll l=s.size();
		ll mid;
		if(l%2==1){
			mid=(l+1)/2;
		}else{
			mid=l/2;
		}
		if(l%2==1){
			for(ll i=mid-2;i>=0;i--){
				c1+=s[i]; 
			}
			for(ll i=mid;i<l;i++){
				c2+=s[i];
			}
		}else{
			for(ll i=mid-1;i>=0;i--){
				c1+=s[i];
			}
			for(ll i=mid;i<l;i++){
				c2+=s[i];
			}
		}
		ll len=c1.size();
		for(ll i=0;i<len;i++){
			if(c1[i]!=c2[i]){
				cnt++;
			}
		}
		cout<<cnt*x;
	}else{
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		ll l=s.size();
		ll mid;
		if(l%2==1){
			mid=(l+1)/2;
		}else{
			mid=l/2;
		}
		if(l%2==1){
			for(ll i=mid-2;i>=0;i--){
				c1+=s[i]; 
			}
			for(ll i=mid;i<l;i++){
				c2+=s[i];
			}
		}else{
			for(ll i=mid-1;i>=0;i--){
				c1+=s[i];
			}
			for(ll i=mid;i<l;i++){
				c2+=s[i];
			}
		}
		ll len=c1.size();
		for(ll i=0;i<len;i++){
			if(c1[i]!=c2[i]){
				cnt++;
			}
		}
	cout<<cnt;
	}
	return 0;
} 
