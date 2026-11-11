#include <iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],b[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k=1;
		while(a[i]*10/2!=0)
		{
			b[i]+=a[i]%2*k;
			k*=10;
			a[i]/=2;
		}
	}
	int num=b[1];
	for(int i=2;i<=m;i++)
	{
		int sum1=num+b[i];
		int sum2=sum1;
		int k=1;
		while(sum1*10/2!=0)
		{
			if(sum1%10>=2 || sum1%2==0)
			{
				if(sum1%10!=0)
				{
			    	sum2-=2*k;
		    		sum2+=10*k;
		    		sum1/=10;
		    		k*=10;
		    	}
			}
		}
		num=sum2;
	}
	int num1=0;
	int f=1;
	while(num*10/10!=0)
	{
		num1+=num%10*f;
		num/=10;
		f*=2;
	} 
	cout<<num1;
	return 0;
}
