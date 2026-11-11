#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn=-2e9;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	int sum=a[1];
	for (int i=1;i<=n;i++){
		sum&=a[i];
	}
	if (m==1){
		cout << maxn;
	}else if (m==2){
		int xo,maxx;
		for (int i=1;i<=n;i++){
			xo=a[i];
			for (int j=i+1;j<=n;j++){
				maxx=max(maxx,xo&a[j]);
			}
		}
		cout << maxx;
	}else if (m==n){
		cout << sum;
	}else if (m==n-1){
		sort(a+1,a+n+1);
		int res=a[2];
		for (int i=3;i<=n;i++){
			res&=a[i];
		}
		cout << res;
	}else{
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for (int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout << ans;
	}
	return 0;
}
