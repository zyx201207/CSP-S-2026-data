#include<iostream>
#include<cstdio>
using namespace std;
char b[1000000];
long long a[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i=1;
	long long k=0;
	cin>>n;
	int j=n;
	for(int p=1;p<=n;p++)
	{
		cin>>a[p]>>b[p];
	}
	while(i<j)
	{
		if(a[i]<a[j])
		{
			if(b[i]!=b[j])
				k+=a[i];
			a[j]=a[j]-a[i];
			i++;
		}
		else if(a[i]>a[j])
		{
			if(b[i]!=b[j])
				k+=a[j];
			a[i]=a[i]-a[j];
			j--;
		}
		else
		{
			if(b[i]!=b[j])
				k+=a[j];
			i++;
			j--;
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
