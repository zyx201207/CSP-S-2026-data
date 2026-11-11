#include<iostream>
using namespace std;
long long a[200005]={},mid=0,i1,i2,sum1,sum2,ans;
char b[200005]={};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		mid=mid+a[i];
	}
	if(mid%2==0)
	{
		mid=mid/2;
		int midl=mid,midr=mid+1;
		for(;midl>=1;midr++,midl--)
		{
			for(i1=1,sum1=0;sum1<midl;i1++)
			{
				sum1=sum1+a[i1];
			}
			for(i2=1,sum2=0;sum2<midr;i2++)
			{
				sum2=sum2+a[i2];
			}
			if(b[i1-1]!=b[i2-1])ans++;
			cout<<i1<<" "<<i2<<endl;
		}
	} 
	else 
	{
		mid=mid/2+1;
		int midl=mid-1,midr=mid+1;
		for(;midl>=1;midr++,midl--)
		{
			for(i1=1,sum1=0;sum1<midl;i1++)
			{
				sum1=sum1+a[i1];
			}
			for(i2=1,sum2=0;sum2<midr;i2++)
			{
				sum2=sum2+a[i2];
			}
			if(b[i1-1]!=b[i2-1])ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);	
} 
