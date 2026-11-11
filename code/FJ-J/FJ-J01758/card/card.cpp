#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], b[500005];
int sum[300005], vis[300005];

int main (){
	freopen( "card.in", "r", stdin );
	freopen( "card.out", "w", stdout );
	cin >> n >> m;
	for ( int i=1; i<=n; i++ ){
		cin >> a[i];
	}
	for ( int i=1; i<=n; i++ ){
		int s = 0;
		for ( int j=i; j<=n; j++ ){
			if ( vis[a[j]] > 0 ){
				for ( int k=vis[a[j]]; k<=s; k++ ){
					if ( b[k] != a[j] && vis[b[k]] > vis[a[j]] ){
						vis[b[k]] = 0;
					}
				}
				s = vis[a[j]];
				b[s] = a[j];
			}
			else{
				s++;
				vis[a[j]] = s;
				b[s] = a[j];
			}
		}
//		for ( int j=1; j<=s; j++ ){
//			cout << b[j] << " ";
//			b[j] = 0;
//		}
//		cout << endl;
		for ( int j=1; j<=m; j++ ){
//			cout << vis[j] << " ";
			if ( vis[j] > 0 ){
				sum[j]++;
			}
			vis[j] = 0;
		}
//		cout << endl;
//		for ( int j=1; j<=m; j++ ){
//			cout << sum[j] << " ";
//		}
//		cout << endl << endl;
	}
	for ( int i=1; i<=m; i++ ){
		cout << sum[i] << " ";
	}
	return 0;	
}
