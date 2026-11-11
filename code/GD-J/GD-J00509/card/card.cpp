#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b[300010];
ll a[500010];
ll l[500010];
ll ans[500010];
ll n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll i,j;
	cin>>n>>m;
	for(i=1; i<=n; i++) cin>>a[i];
	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++) b[j]=l[j]=0;
		ll p=0;
		for(j=i; j<=n; j++) {
			if(b[a[j]]==0) {
				p++;
				l[p]=a[j];
				b[a[j]]=p;
			} else {
				ll t=p; 
				p=b[a[j]];
				l[p]=a[j];
				for(int k=b[a[j]]+1; k<=t; k++) b[l[k]]=l[k]=0;
			}
		}
		for(j=1; j<=p; j++) ans[l[j]]++;
	}
	for(i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
}
