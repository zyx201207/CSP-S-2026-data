#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,a[100000005],l,ans;
string s,c,q,p;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(ll j=0;j<a[i];j++){
			s+=c[i];			
		}
	}
	l=s.size()/2;
	if(s.size()%2==0){
		for(ll i=0;i<l-1;i++) p+=s[i];
		for(ll j=l;j<s.size();j++) q+=s[j];
		for(ll k=0;k<l;k++){
			if(p[k]!=q[k]){
				ans++;
			}
		}
	}
	else{
		for(ll i=0;i<l;i++) p+=s[i];
		for(ll j=l;j<s.size()-1;j++) q+=s[j];
		for(ll k=0;k<l;k++){
			if(p[k]!=q[k]){
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}

