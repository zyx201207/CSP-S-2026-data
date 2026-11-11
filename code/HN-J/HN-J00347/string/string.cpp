#include<bits/stdc++.h>
using namespace std;
char c[1000005],s;
int n,a[1000005],d;
int sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s;
		for(int j=1;j<=a[i];j++)
		{
			d++;
			c[d]=s;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			break;
		}
		if(i==n-1)
		{
			for(int j=1;j<=d/2;j+=a[i])
			{
				if(c[j]!=c[d-j+1]){
					sum+=a[i];
					c[j]=c[d-j+1];
				}
			}
			cout<<sum;
			return 0;
		}	
	}
	for(int i=1;i<=d;i++)
	{
		if(c[i]!=c[d-i+1]){
			sum++;
			c[i]=c[d-i+1];
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
