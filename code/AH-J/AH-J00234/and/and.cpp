#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int f[1005][1005]={0},a[1005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ma=a[1];
	f[1][1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		f[i][1]=ma;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			f[i][j]=max(f[i-1][j],(f[i-1][j-1]&a[i]));
		}
	}
	cout<<f[n][m];
	return 0;
}
