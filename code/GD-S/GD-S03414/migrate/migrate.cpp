#include <bits/stdc++.h>
using namespace std;
int sum[10001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 0;i < t;i++){
		int n,d;
		cin >> n >> d;
		int x[n];
		for(int j = 0;j < n;j++)cin >> x[i];
		for(int j =0;j < n;j++){
			for(int u = j+1;u < n;u++){
				if(x[u] - x[j] % d != 0 && x[u] - x[j] > d)sum[i]++;
			}
		} 
		cout << sum[i] << endl;

	}
	return 0;
} 
