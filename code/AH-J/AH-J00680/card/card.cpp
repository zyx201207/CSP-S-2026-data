#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010],cnt[3010];
int main(){
	ll n,m,maxn=-1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		maxn=max(maxn,a[i]);
	}
	if(m==1) cout<<maxn;
	else{
		for(ll i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
	}
	return 0;
}
