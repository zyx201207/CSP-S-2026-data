#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long c,t,n,d,a[2000005],xx,ans,b[2000005][3];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1; i<=t; i++) {
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&a[j]);
		}
		for(int j=1;j<=n;j++){
			b[0][j]=j-(lower_bound(a+1,a+j+1,a[j]-d)-a);
			b[1][j]=upper_bound(a+j+1,a+n+1,a[j]+d)-a-j-1;
	    }
	    for(int j=1;j<=n;j++){
	    	printf("");
	    	for(int k=j+b[1][j];k<=n;k++){
	    		if(((b[1][j]+j)-(k-b[0][k])==1)&&(b[0][k]>=2&&b[1][j]>=2)){
				   ans++;
		
				   break;
				}
	        }
	    }
	    printf("%lld\n",ans);
    }
        return 0;
    }
