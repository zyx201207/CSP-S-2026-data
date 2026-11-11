#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int w_opt,t,n,w_ans;
long long m,a[2000005],f[5005][5005];
int main()
{
//	freopen("migrate1.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&w_opt,&t);
	while(t--)
	{
		w_ans=0;
		scanf("%d %lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(i+m/(a[2]-a[1])+m/(a[2]-a[1])-1<=n)
				w_ans++;
		}
		printf("%lld\n",w_ans);
//		for(int i=1;i<=n;i++)
//		{
//			f[i][0]=i;
//			f[i][1]=upper_bound(a+1+i,a+1+n,a[i]+m)-a-1;
//			if(a[n]-a[i]<=m)
//				f[i][1]=n;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				f[i][j]=f[f[i][j-1]][1];
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
////				printf("f[%d][%d]=%d\n",i,j,f[i][j]);
//				if(f[i][j]==f[i][j-1])
//					break;
//				int w_temp=0;
//				for(int k=1;k<j;k++)
//				{
//					if(f[f[i][k]-1][j-k]>=f[i][j])
//					{
//						w_temp++;
//						if(w_temp>1)
//							break;
//						if(f[f[i][k]-2][j-k]>=f[i][j])
//							break;
//					}
//				}
////				printf("i=%d,j=%d,%d\n",i,j,w_temp);
//				if(w_temp==1)
//					w_ans++;
//			}
//		}
//		printf("%d\n",w_ans);
	}
	return 0;
}
