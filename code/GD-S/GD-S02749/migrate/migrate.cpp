#include<iostream>
using namespace std;

int c,t;
int n,d;
int a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 1;i <= n;i++){
			int cnt = 0;
			for (int j = 1;j < i;j++){
				if ((a[i] - a[j] + 1) % (d + 2) == 0){
					cnt++;
				}
			}
			ans += cnt;
		}
		cout << ans << '\n';
	}
} 
