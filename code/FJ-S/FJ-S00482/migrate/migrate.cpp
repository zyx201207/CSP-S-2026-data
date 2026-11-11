#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;

int c,n,d,a[N],l[N],r[N];

void solve(){
	cin >> n >> d;
	int ans = 0;
	for(int i=1;i<=n;i++){
		l[i] = 0;
		r[i] = 0;
		cin >> a[i];
	}
	for(int i=2;i<n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j] <= d && a[i+1]-a[j] > d){
				if(!l[i])l[i] = 1;
				l[i] += l[j];
//				break;			
			}

		}
	}
	for(int i=n;i>=2;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i] <= d && a[j]-a[i-1] > d){
				if(!r[i])r[i] = 1;
				r[i] += r[j];
//				break;			
			}

		}
	}
	for(int i=1;i<=n;i++){
//		cout << l[i] << " " << r[i] << '\n';
		int j = i+1;
		for(j;j<=n;j++){
			if(a[j] - a[i] > d)break;
		}
		if(j == n+1)break;
		if(j - i == 1)continue;
		int f = j,k = i+1;
//		cout << i << " " << f << '\n';
		for(j;j<=n;j++) {			
			while(a[j] - a[k] > d){
				k++;
				if(f-k==1)break;
			}
//			cout << k << " ";
			if(f-k==1)break;
			if(f-k==2)ans+=1+l[i] + r[j] + l[i]*r[j];
		}
//		cout << '\n' << '\n';
	}
	cout << ans << '\n';
//	cout << '\n' << '\n';
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
	cin >> c >> T;
	while(T--)solve();
	return 0;
}
/*
5 3
-3 0 2 3 4
*/
