#include<bits/stdc++.h>//暴力枚举- 
using namespace std;
const int N=2000005;
int c,t,n,m,a[N];
int main(){//等差 测试点11,12- 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int x=1;x<=t;x++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(m%2==0){
			if(a[3]-a[1]<=m){
				printf("%d\n",n-m-1);
			}else{
				printf("0\n");
			}
		}else{
			if(a[m+2]-a[(m+3)/2]<=m && a[m+1]-a[(m+3)/2]>m){
				printf("%d\n",n-m-1);
			}else{
				printf("0\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
