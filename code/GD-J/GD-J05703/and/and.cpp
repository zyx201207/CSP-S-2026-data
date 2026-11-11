#include <bits/stdc++.h>
using namespace std;

int n,m;
int f[200010];
int maxn;

bool cmp(int a,int b) {
	int va=maxn&a;
	int vb=maxn&b;
	return va>vb;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>f[i];
	}
	
	int ans,value;
	for(int i=1;i<=n;i++) {
		value=maxn=f[i];
		sort(f+1,f+1+n,cmp);
		for(int j=1;j<=m;j++) {
			value=value&f[j];
		}
		ans=max(ans,value);
	}
	
	cout<<ans;
	
	return 0;
}
