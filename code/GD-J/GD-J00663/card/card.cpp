#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500005];
ll ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		if(a[i]==a[i-1])continue;
		else cout<<i<<" ";
	}
	return 0;
}

