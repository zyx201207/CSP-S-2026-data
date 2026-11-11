#include<bits/stdc++.h>
using namespace std;
 int a[200005];
char b[200005]; 
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<j)
	{
		if(b[i]==b[j])
		{
			if(a[i]==a[j])
			{
				i++;
				j--;
			}
			else
		{
				if(a[i]>a[j])
			{
				j--;
				a[i]=a[i]-a[j];
			}
			else
			{
				i++;
				a[j]=a[j]-a[i];
			}
		}
			
		}
		else
		{
			if(a[i]==a[j])
			{
				sum=sum+a[i];
				i++;
				j--;
			}
			else
		{
				if(a[i]>a[j])
			{
				sum=sum+a[j];
				a[i]=a[i]-a[j];
				j--;
			}
			else
			{
				sum=sum+a[i];
				a[j]=a[j]-a[i];
				i++;
			}
		}
		}
	}
	cout<<sum;
	return 0;
}
