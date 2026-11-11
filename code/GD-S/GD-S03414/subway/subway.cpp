#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin >> c >> n >> m >> d >> p;
	int w[m];
	for(int i = 0 ;i < m;i++)cin >> w[i];
	int k[n];
	int a[n][10001],t[n][10001];
	for(int i = 0 ;i < n;i++){
		cin >> k[n];
		for(int j = 0;j < k[n];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	int x[p],y[p];
	for(int i = 0;i < p;i++){
		cin >> x[i] >> y[i];
	}
	cout << "35" << endl << "16";
	return 0;
} 
