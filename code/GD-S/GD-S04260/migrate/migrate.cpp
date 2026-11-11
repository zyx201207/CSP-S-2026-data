#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c,t;
int di[N],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			di[i] = 0;
		}
		for(int i = 2; i <= n; i++){
			di[i] = abs(a[i] - a[i - 1]); 
		}
		int sum = 0;
		for(int i = 2; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				sum += di[j];
				if(sum / d == 1 && sum % d != 0){
					ans++;
				}else if(sum / d == 2 && sum % d == 0){
					ans++;
				}
			}
		}
		cout << ans << endl; 
	}
	return 0;
}
