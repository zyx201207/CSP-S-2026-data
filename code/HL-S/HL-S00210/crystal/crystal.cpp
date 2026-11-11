#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500005;
ll n,m,ans;
ll a[N],b[N];

ll ssum(ll x[]){
	ll sum = 0;
	for(int i=1;i<=n;i++){
		if(x[i]==-1) break;
		sum += x[i];
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[i]){
				b[i] = -1;
				break;
			}
			if(i==j) continue;
			b[j] = a[i] - a[j];
		}
		if(ssum(b)<=m) ans++;
	}
	cout << ans;
	return 0;
}

