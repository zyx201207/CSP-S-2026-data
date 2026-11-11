#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,op[200010],sum[200010];
void dfs(int con,int x) {
	if (x>n) {
		return;
	}
	op[con]=a[x];
	if (con==m) {
		for (int i=2;i<=con;i++) {
			op[i]=op[i]&op[i-1];
		}
		ans=max(ans,op[m]);
		return;
	}
	for (int j=x+1;j<=n;j++) {
		dfs(con+1,j);
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (m==1) {
			ans=max(ans,a[i]);
		}
	}
	if (m==1) {
		cout << ans << endl;
		return 0;
	}
	if (m==2) {
		for (int i=1;i<n;i++) {
			for (int j=i+1;j<=n;j++) {
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (m==n) {
		sum[1]=a[1];
		for (int i=2;i<=n;i++) {
			sum[i]=sum[i-1]&a[i];
		}
		cout << sum[n] << endl;
		return 0;
	}
	for (int i=1;i<=n;i++) {
		dfs(1,i);
	}
	cout << ans << endl;
	return 0;
}
