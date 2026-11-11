#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005],c[100005];
signed main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			b[j] = a[j];
		}
		for (int j = i;j < n;j++){
			if (b[j] == b[j+1]) b[j] = 0;
		}
		for (int j = i;j <= n;j++){
			c[b[j]]++;
		}
		
	}
	for (int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
}
