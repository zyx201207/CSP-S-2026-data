#include<iostream>
using namespace std;
int a[200005];
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		if(ch[i]!=ch[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				sum+=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
	
				a[j]-=a[i];
				sum+=a[i];
				i++;
			}
			else 
			{
				sum+=a[i];
				a[i]=0;
				a[j]=0;
				i++,j--;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				
				
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]<a[j])
			{
				
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
			else
			{
				i++,j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
