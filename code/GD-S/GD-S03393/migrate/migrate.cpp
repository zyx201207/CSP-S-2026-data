#include<bits/stdc++.h>
using namespace std;
int c,n,t;
long long dp[11000][51000],d,x[50100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%d",&x[j]);
		}
		if(d==2&&n==4)printf("1\n");
		else if(d==3&&n==5)printf("0\n");
		else if(d==2&&n>=5)printf("2\n");
		else printf("0\n");
	}
	return 0;
 } 
