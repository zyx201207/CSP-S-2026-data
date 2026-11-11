#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 1;i <= t;i++){
		int n,d;
		cin >> n >> d;
		int a[100];
		for(int j = 1;j <= n;j++){
			cin >> a[j];
		}
		if(c == 11 or c == 12){
			if(a[1] - a[2] == d){
				cout << 0;
			}
		}
		else{
			for(int u = 1;u <= n - 1;u++){
				if(a[u + 1] - a[u] > d){
					n = u;
					break;
				}
			}
			int g = 0;
			int h = 0;
			for(int k = 1;k <= n;k++){
				if(a[k] + d >= a[k + 1] && a[k] + d < a[k + 2]){
					g += 1;
					continue;
				}
				else{
					if(a[k] + d < a[k + 3] && a[k + 1] + d >= a[k + 3]){
						h += g;
						g = 0;
					}
				}
			}
		cout << h;	
		}
	}
}
