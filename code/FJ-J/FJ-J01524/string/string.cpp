#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200005];
ll ans=0;
char s[200005];
ll x,y;
ll cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		cin>>s[i];
	}
	ll j=n;
	if(ans%2==0){
		for(ll i=1;i<=n/2;i++){
			if(s[i]!=s[j]){
				if(a[i]==a[j]){
					cnt+=a[i];
				}else{
					cnt+=min(a[i],a[j]);
				}
			}
			j--;
		}
	}
	
	cout<<cnt;
	return 0;
}
