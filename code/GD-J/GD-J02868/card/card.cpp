#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =5e5+10, M=3e5+10;
ll n, m, a[N], ans[M], mlast[M];
bool A=true;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(ll i=1; i <= n; ++i){
		cin >> a[i];
		mlast[a[i]] = i;
		if(a[i]<a[i-1]) A=false;
	}
	
	if(A){
		for(ll i=1; i<=m;++i){
			cout << mlast[i]<<' ';
		}
		return 0;
	}
	
	for(ll i=1; i<=n; ++i){
		ll j=i;
		while(j<= n){
			j = mlast[a[j]];
			ans[a[j]]++;
			++j;
		}
	
	}
	
	for(ll i=1; i<= m; ++i){
		cout << ans[i]<<' ';
	}
	return 0;
}

