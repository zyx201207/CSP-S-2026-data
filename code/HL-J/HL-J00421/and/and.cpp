#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin>>tie(0);
	freopen("and.in""r",stdin);
	freopen("and.out""w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cina[i];
	}
	int maxa=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				c=a[i]&a[j+l-1];
			}
			maxa=maxa(c,maxa);
		}
	}
	cout<<maxa;
	return 0;
} 
