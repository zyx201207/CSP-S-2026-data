#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n,fp,ans = 0;
long long m,a[MAXN],sum[MAXN],neg[MAXN],pos[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int f = 1;
	for (int i = 1; i <= n-2; i++){
		if (a[i] != a[i+1] || a[i+1] != a[i+2]){
			f = 0;
			break;
		}
	}
	if (f){
		for (int i = n; i >= 1; i--){
			if ((a[i] + a[1]) / 2 * i <= m)
				cout << i;
		}
	}
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + abs(a[i]);
		neg[i] = neg[i-1];
		pos[i] = pos[i-1];
		if (a[i] < 0)
			neg[i] += a[i],fp = i + 1;
		else 
			pos[i] += a[i];
	}
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			int len = j - i + 1;
			if (len * a[j] - (pos[j] - pos[i - 1] + neg[i - 1] - neg[j]) <= m){
				int canup = m - (len * a[j] - (pos[j] - pos[i - 1] + neg[i - 1] - neg[j]));
				ans = max(ans,len);
				for (int k = j + 1; k <= n; k++){
					if (a[k] - a[j] <= canup / (k - i + 1)){
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
