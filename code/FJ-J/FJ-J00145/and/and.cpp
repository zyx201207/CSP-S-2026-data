#include<bits/stdc++.h>
#define long long ll
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
int sb[MAXN];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ans = -1e9+8;
	for(int k=1;k<=n-m;k++){
		for(int i=1;i<=m;i++){
			for(int j=k;j<=n;j++){
				sb[i] = a[j];
			}
		} 
		int sum = sb[1];
		for(int i=2;i<=m;i++){
			sum &= sb[i];
		}
		ans = max(ans,sum);
	}
	cout << ans << "\n";
	return 0;
}
