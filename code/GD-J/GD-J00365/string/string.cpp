#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],l,ans,b[200005],len;
char c;
string s="|",t="|";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c;
		s+=c;
		len+=a[i];
	}
	ll j=l-1,ii=1;
	for(ll i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			b[ii]+=a[i];
			l--;
			continue;
		}
		t+=s[i];
		b[i]+=a[ii];
		ii++;
	}
	ans+=(len+1)/2;
	if(len%2==1){
		ans--;
		for(ll i=1,mn=0;i<t.size();i++){
			mn+=b[i];
			if(mn>=(len+1)/2){
				b[i]--;
				len--;
				break;
			}
		}
	}
	for(ll i=1;i<t.size();i++){
		if(t[i]==t[t.size()-i]){
			ans-=min(b[i],b[t.size()-i]);
		}
		if(b[i]<=b[t.size()-i]){
			b[i+1]-=abs(b[i]-b[t.size()-i]);
			b[i]=b[t.size()-i];
		}
		else{
			b[t.size()-i-1]-=abs(b[i]-b[t.size()-i]);
			b[t.size()-i]=b[i];
		}
	}
	cout<<ans;
	return 0;
}
