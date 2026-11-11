#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000100],r[2000100],f[2000100];
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(long long i=1,j=1;i<=n;i++)
		{
			while(a[j+1]-a[i]<=d&&j+1<=n)j++;
			r[i]=j;
		//	cout<<i<<" "<<r[i]<<endl;
		}
		long long s=0; 
		for(long long i=1,qi=1;i<=n;i++)
			if(r[i]==i)
			{
				long long zhong=i,ji=0;
				for(long long j=zhong;j>=qi;j--)
				{
					long long chang=r[j]-j;
					if(chang==1)
					{
						f[j]=f[r[j]];
					}
					if(chang==2)
					{
						f[j]=r[r[j]-1]-r[j];
					//	if(j==4)cout<<"***"<<f[j]<<endl; 
						if(r[r[j]-1]==r[r[j]])
						f[j]+=(zhong-r[r[j]])-f[r[j]];
						else
						{
							f[j]+=f[r[r[j]]]-f[r[r[j]-1]];
						}
						//if(j==4)cout<<"***"<<f[j]<<endl;
					} 
					if(chang>2)
					{
						f[j]=r[r[j]-1]-r[r[j]-2];
						if(r[r[j]-1]==r[r[j]]&&r[r[j]]==r[r[j]-2])continue;
						if(r[r[j]-1]==r[r[j]])
						f[j]+=(zhong-r[r[j]])-f[r[j]];
						else
						{
							f[j]+=f[r[r[j]]]-f[r[r[j]-1]];
						}
					}
				}
				for(long long j=qi;j<=zhong;j++)s+=f[j];
				qi=i+1;
			}
//	for(int i=1;i<=n;i++)cout<<f[i]<<endl;
		for(long long i=0;i<=n+1;i++)f[i]=0,r[i]=0,a[i]=0;
		printf("%lld\n",s);
	}
}
/*
0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
