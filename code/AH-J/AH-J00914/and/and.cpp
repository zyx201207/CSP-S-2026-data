#include <bits/stdc++.h>
using namespace std;
bool cmp (int x,int y) {
	return x>y;
}
int n,m,ans;
int a[200005];
void dfs (int i,int y,int cnt) {
	if (cnt==m) {
		ans=max(ans,y);
		return;
	}
	if (i==n) return;
	if (y==0) dfs (i+1,a[i],cnt+1);
	else dfs (i+1,y&a[i],cnt+1);
	dfs (i+1,y,cnt);
	return;
}
int main () {
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,mn=1e9,yu=(1<<30)-1;
	for (int i=0;i<n;i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		yu&=a[i];
	}
	if (m==1) {
		cout<<mx;
		return 0;
	} else if (m==n) {
		cout<<yu;
		return 0;
	} else if (m==2) {
		int as=0;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (i==j) continue;
				as=max (as,a[i]&a[j]);
			}
		}
		cout<<as;
		return 0;
	} else if (m==n-1) {
		int as=(1<<30)-1;
		for (int i=0;i<n;i++) {
			if (a[i]!=mn) as&=a[i];
			else mn=-1;
		}
		cout<<as;
		return 0;
	} else if (n>25) {
		sort (a,a+n,cmp);
		int as=(1<<30)-1;
		for (int i=0;i<m;i++) {
			as&=a[i];
		}
		cout<<as;
		return 0;
	}
	dfs (0,0,0);
	cout<<ans;
	return 0;
}
