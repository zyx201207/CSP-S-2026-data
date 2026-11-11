#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],midx,mid=1e12,ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=2;i<=n;i++){
		ll d=0;
		ans=1;
		for (int j=i-1;j>=1;j--){
			ans++;
			if (d==m)break;
			if (d>m){
				ans--;break;
			}
			d+=(a[i]-a[j]);
		}
		if (d>=m)break;
	}
	cout << ans;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

