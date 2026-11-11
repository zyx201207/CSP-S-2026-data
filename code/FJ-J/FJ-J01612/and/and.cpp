#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn], ceng[60], d[maxn], g[maxn];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ceng[0] = 1;
	for(int i = 1; i <= 30; i++) ceng[i] = ceng[i-1]*2;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int sum;
	for(int i = 30; i >= 0; i--){
		sum = i;
		if(ceng[i] <= a[n]) break;
	}
	for(int i = sum; i >= 0; i--){
		int cnt=0;
		for(int j = n; j >= 1; j--){
			int dd = a[j]&ceng[i];
			if(dd > 0){
				cnt++;
				d[cnt] = a[j];
			}
		}
		if(cnt >= m){
			sum = i-1;
			sort(d+1,d+n+1);
			int ans=0;
			for(int k = sum; k >= 0; k--){
				int cnt1=0;
				for(int l = n; l >= 1; l--){
					int dd = d[l]&ceng[k];
					if(dd > 0){
						cnt1++;
						g[cnt1] = d[l];
					}
				}
				if(cnt1 >= m){
					sort(g+1,g+cnt1+1);
					ans = g[cnt1];
					for(int l = cnt1-1; l >= cnt1-m+1; l--){
						ans = ans&g[l];
					}
					cout << ans;
					return 0;
				}
			}
			ans = d[cnt];
			for(int j = cnt-1; j >= cnt-m+1; j--){
				ans = ans&d[j];
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
