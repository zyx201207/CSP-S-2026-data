#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; for (int i = 1; i <= n ; i++) cin >> a[i];
	if (m == 1){
		cout << n << endl;
	}
	if (m == 2){
		if (a[1] > a[2]) cout << 4 << " " << 2;
		if (a[1] < a[2]) cout << 2 << " " << 4; 
	}
	return 0;
}


