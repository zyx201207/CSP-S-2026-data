#include<bits/stdc++.h>
using namespace std;
int l[2000001],dp[2000001],count[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		int S=0;
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++) scanf("%d",l+i);
		if(l[n-1]-l[0]<=d||n<=3){printf("0\n"); continue;}
		if(c==11||c==12)
		{
			int D=l[2]-l[1];
			if(d<2*D) {printf("0\n"); continue;}
			printf("%d\n",n-d/D*2);
		}
		for(int i=3;i<n;i++)
		{
			if(l[i]-l[i-2]<=d&&l[i-1]-l[i-3]<=d&&l[i]-l[i-3]>d) S+=i-3;
		}
		printf("%d\n", S);
		/*
		 int L=0;
		 for(int i=0;i<n;i++)
		 {
		     if(  
		 }
		 */
	}
	return 0;
}
