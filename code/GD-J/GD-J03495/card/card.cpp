#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
const ll N=5e5+10;
const ll M=3e5+10;
ll a[N],fr[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=n;i>=1;i--){
		if(fr[a[i]]==0){
			fr[a[i]]=i;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j=fr[a[j]]+1){
			ans[a[j]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
