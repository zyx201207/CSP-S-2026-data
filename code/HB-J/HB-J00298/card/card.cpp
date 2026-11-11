#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt,con[500005];
bool b[500005];
int ans[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
;	}
	for (int i=1;i<=n;i++) {
		memset(con,0,sizeof(con));
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++) {
			for (int k=1;k<=cnt;k++) {
				if (con[k]==a[j]) {
					for (int l=k+1;l<=n;l++) {
						con[l]=0;
					}
					cnt=k-1;
					break;
				}
			}
			cnt++;
			con[cnt]=a[j];
		}
		for (int j=1;j<=cnt;j++) {
			if (b[j]==0) {
				b[j]=1;
				ans[con[j]]++;
			}
		}
	}
	for (int i=1;i<=m;i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
