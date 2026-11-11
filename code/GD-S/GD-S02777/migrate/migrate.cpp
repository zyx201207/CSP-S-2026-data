#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int fal[305],ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ans = 0;
		fal[0] = fal[1] = 1;
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				if (a[j] - a[i] <= d){
					int f = 1;
					for (int k = 1; k < i; k++)
						f = fal[k] && f;
					fal[j] += f;
				}
			}
		}
		for (int i = 1; i <= n; i++){
			ans = ans + fal[i] * (fal[i] - 1) / 2;
		}
		cout << ans;
	}
	return 0;
}
