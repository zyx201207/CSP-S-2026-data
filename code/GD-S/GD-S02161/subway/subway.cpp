#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;
long long w[500005],a[500005][3],e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	} 
	for(int i = 0;i < n;i++){
		cin >> k;
		for(int j = 0;j < 2 *k;j++){
			cin >> a[i][j];
			e[i] += a[i][j];
		}
	}
	for(int i = 0;i < q;i++){
		cout << e[i];
	}
	return 0;
}
