#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m,a[N],b[N],c[N];
//mian mian mian
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			b[j]=0;
		}
		for(ll j=i;j<=n;j++){
			if(b[j]==0) b[j]=j;
			else{
				for(ll k=b[j];k<j;k++){
					b[k]=0;
				}
				b[j]=j;
			}
		}
		for(ll j=i;j<=n;j++){
			if(b[j]!=0) c[j]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<c[i];
	}
	return 0;
}
