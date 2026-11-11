#include <bits/stdc++.h>
using namespace std;
int m,n,a[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxx=-1;
	cin>>m>>n;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
				maxx=max(a[i] & a[i+j],maxx);
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
