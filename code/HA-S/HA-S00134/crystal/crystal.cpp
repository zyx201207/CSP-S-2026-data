#include<bits/stdc++.h>
using namespace std;

int n, ans=1;
long long m, a[500001], c[500001];

inline void dfs(int i) {
	if (i==n) {
		int x=0, l=0, r=0;
		for (int j=1;j<n;j++) {
			if (c[j]==0) {
				if (l==0)
					l=j;
				r++;
			}
			else
				l=0, r=0;
			x=max(r-l+1, x);
		}
		x+=1;
		ans=max(ans, x);
		return;
	}
	if (m<=0)
		return;
	for (int j=1;j<n;j++) {
		if (c[j]==0)
			continue;
		c[j]-=1;
		m--;
		dfs(j+1);
		c[j]+=1;
		m++;
	}
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	memset(c, 255, sizeof c);
	for (int i=1;i<n;i++)
		c[i]=a[i+1]-a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
