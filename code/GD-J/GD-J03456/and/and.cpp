#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[7001];
int f[7001][7001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
		}
	}
	printf("%d",f[n][m]);
	return 0;
} 
