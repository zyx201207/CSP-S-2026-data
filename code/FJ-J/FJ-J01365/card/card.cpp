#include<bits/stdc++.h>
typedef  long long  ll;
using namespace std;
ll n,m,a[500005],b[500005],c[500005];
bool f[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll o=1;
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for(ll j=i;j<=n;j++){
			c[o]=a[j];
			o++;
			for(ll k=1;k<=o-1;k++){
				if(c[k]==a[j]){
					for(ll p=k+1;p<=o-1;p++){
						c[p]=0;
					}
				}
			}
		}
		for(ll k=1;k<=o-1;k++)b[c[k]]++; 
	}
	for(ll i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
