#include<iostream>
using namespace std;
long long n,d;
long long a[2000005];
long long l[2000005];
long long fmin[2000005];
long long fc[2000005];
void mmain()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	long long cnt=0;
	for(int j=1;j<=n;j++) 
	{
		for(int i=1;i<=n;i++)
		{
			l[i]=0;
			fmin[i]=fc[i]=0;
		}
		a[j-1]=-4e18;
		 fc[j]=1;
		 fmin[j]=0;
		long long lf=j,lmin=0;
		l[0]=1;
	for(int i=j+1;i<=n;i++)
	{
		while(a[lf]<a[i]-d)
		{
			l[fmin[lf]]-=fc[lf];
			lf++;
			
		}
		while(l[lmin]==0)
		{
			lmin++;
		}
		fmin[i]=lmin+1;
		fc[i]=l[lmin];
		l[fmin[i]]+=fc[i];
		if(fc[i]==2)cnt++;
		//if(fc[i]>2)break;
	}
	}
	printf("%lld\n",cnt);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		mmain();
	 } 
	return 0;
}
