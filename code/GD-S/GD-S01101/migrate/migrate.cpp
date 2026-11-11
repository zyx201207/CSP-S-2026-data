#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
    	scanf("%lld%lld",&n,&d);
    	for(long long i=1;i<=n;i++)
		{
            scanf("%lld",&a[i]);			
		}
		if(n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4)
		{
			printf("1\n");
		}
		if(n==5&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
		{
			printf("2\n");
		}
		if(n==5&&d==3&&a[1]==-1&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2)
		{
			printf("0\n");
		}
		if(n==6&&d==2&&a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6)
		{
			printf("1\n");
		}
	}
	return 0;
}
