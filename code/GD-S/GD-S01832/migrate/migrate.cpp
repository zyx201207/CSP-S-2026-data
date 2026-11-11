#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
0 1
5 3
-3 0 2 3 4
*/
const int N=305;
int cs,T;
int n;
ll d;
ll a[N];
int f[N][N];
int calc(int l,int r) {
	int cnt=0;
	for (int i=l;i<r;) {
		int flag=0;
		for (int j=r;j>i;j--) {
			if (a[j]-a[i]<=d) {
				i=j;
				cnt++;
				flag=1;
				break;
			}
		}
		if (flag==0) {
			return 0;
		}
	}
	return cnt;
}
int check(int i,int j) {
	int cnt=0;
	for (int k=i+1;k<j;k++) {
		if (f[i][k]*f[k][j]==0) {
			continue;
		}
		if (f[i][k]+f[k][j]==f[i][j]) {
			cnt++;
		}
		if (cnt>=3) {
			return 0;
		}
	}
	if (cnt==2) return 1;
	return 0;
}
void solve() {
	for (int i=1;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			f[i][j]=calc(i,j);
//			printf("[%d %d %d]\n",i,j,f[i][j]);
		}
	}
	int ans=0;
	for (int i=1;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			ans+=check(i,j);
		}
	}
	printf("%d\n",ans);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&cs,&T);
	while (T--) {
		scanf("%d %lld",&n,&d);
		for (int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
		}
		solve();
	}
	return 0;
}
