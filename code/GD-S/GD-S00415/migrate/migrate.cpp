#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 2;
int c, t, n;
long long d, x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin >> c >> t;
	int cnt = 0;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(x[j] == x[i] + d + 1){
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
