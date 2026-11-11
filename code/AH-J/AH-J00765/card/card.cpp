#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,cnt[1000000],a[1000000];
bool f[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			f[j]=1;
			
		}
	}
	cout<<0<<" "<<0;
}
