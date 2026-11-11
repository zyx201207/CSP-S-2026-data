#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[3000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d %d",&n,&d);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		long long b=a[1]-a[0],k=1; 
		for(int i=1;i<n;i++) if(a[i]-a[i-1]!=b) k=0;
		if(k==1 && 2*b<=d){
			for(int i=0;i<n;i++){
				for(long long j=1;j<d;j++){
					if(a[i]+d+j==a[i+d+j]) ans++;
				}
			}
		} 
		printf("%d\n",ans);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 4
1 3 5 7 9

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

