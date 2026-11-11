#include <bits/stdc++.h>
using namespace std;
const int maxna=2e5+5;
const int maxnb=5e3+10;
int n,m;
long long a[maxna];
long long f[maxnb][maxnb];
long long Max;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Max=max(a[i],Max);
	}
	f[0][0]=Max;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
		}
	}
	printf("%d",f[n][m]);
	return 0;
}

