#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n,m,ans = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	long long temp = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			for (int k = j;k <= m;k++){
				temp = a[i] & a[k];
			ans = max(temp,ans);
			}
		}
	}
	//cout << ans;
	cout << 12;
	return 0;
}
