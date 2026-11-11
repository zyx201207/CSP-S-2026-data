//GZ-J00624 毕节梁才学校  赵纤茹
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20000+10];
int f[20000+10][20000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f[0][0]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			f[i][j]=max((f[i-1][j-1]&a[i]),f[i-1][j]);
		}
	}
	printf("%d",f[n][m]);
	return 0;
}
