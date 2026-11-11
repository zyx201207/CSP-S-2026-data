#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[40],w[40][200005],id[40],pw[40],maxn,sum=0,ans;
bool f[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		int c=a[i],jw=0;
		while(c) {
			++jw;
			c/=2;
		}
		maxn=max(maxn,jw);
	}
	for(int i=1; i<=n; i++) {
		int x=0,c=a[i];
		while(x<=maxn) {
			++x;
			if(c%2==1) id[x]++;
			else w[x][++s[x]]=i;
			c/=2;
		}
	}
	sum=n;
	pw[0]=1;
	for(int i=1; i<=n; i++) f[i]=1;
	for(int i=1; i<=30; i++) pw[i]=pw[i-1]*2;
	for(int i=35; i>=1; i--) {
		if(id[i]<m) continue;
		int su=sum;
		for(int j=1; j<=s[i]; j++) {
			if(f[w[i][j]]==1) su--;
		}
		if(su>=m) {
			ans+=pw[i-1];
			for(int j=1; j<=s[i]; j++) {
				if(f[w[i][j]]==1) sum--,f[w[i][j]]=0;
			}
		}
	}
	cout << ans;
	return 0;
}
