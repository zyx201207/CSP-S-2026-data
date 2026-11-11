#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001],ans[3001],b[3001],q[5001];
int main() {
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int j=1; j<=n; j++) {
		memset(q,0,m);
		memset(b,0,m);
		for(int i=1;i<=m;i++)cout<<q[i];
		int p=0;
		for(int i=j; i<=n; i++) {
			if(b[a[j]]==-1) {
				b[a[j]]=++p;
				q[p]=a[j];
			} else p=b[a[j]];
		}
		for(int i=1; i<=p; i++) {
			ans[q[i]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

