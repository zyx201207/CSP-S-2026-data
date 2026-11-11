#include<iostream>
using namespace std;

int a[200005];
char b[2000005];
long long ans=0;

int main()
{
	fopen("string.in","r");
	fopen("string.out","w");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	while(i<j)
	{
		if(b[i]!=b[j])
		{
			if(a[i]<a[j])
			{
				ans+=a[i];
				i+=1;
				a[j]-=a[i];
			}
			else if(a[i]==a[j])
			{
				ans+=a[i];
				i+=1;
				j-=1;
			}
			else
			{
				ans+=a[j];
				j-=1;
				a[i]-=a[j];
			}
		}
		else
		{
			if(a[i]<a[j])
			{
				i+=1;
				a[j]-=a[i];
			}
			else if(a[i]==a[j])
			{
				i+=1;
				j-=1;
			}
			else
			{
				j-=1;
				a[i]-=a[j];
			}
		}
	} 
	cout<<ans;
	return 0;	
}
