#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000005;
ll c,t,n,d,mn,ans;
ll a[N],b[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			mn = min(mn,a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			a[i] += abs(mn);
		}
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				
				if(a[i]+d>=a[j]) b[j]++;
			}
			for(int j=1;j<=n;j++){
				cout << b[j]<< ' ';
			}
			cout << endl;
		}
		for(int i=1;i<=n;i++){
			cout << b[i] << ' ';
			if(b[i]==2) ans++;
			b[i] = 0;
		}
		cout << ans << endl;
		ans=0;mn=0;
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

/*
0 4
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

