#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=200010;
ll a[maxn];
char c[maxn];
ll m[maxn];
char d[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,s=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		s+=a[i];
	}
	for(ll i=1;i<=n;i++){
		m[i]=m[i-1]+a[i];
	}
	for(ll i=1;i<=s;i++){
		for(ll j=1;j<=n;j++){
			if(i<=m[j]){
				d[i]=c[j];
				break;
			}
		}
	}
	ll l,ans=0;
	l=s/2+1;
	if(s%2!=0) l++;
	for(ll i=l;i<=s;i++){
		if(d[i]!=d[s-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
