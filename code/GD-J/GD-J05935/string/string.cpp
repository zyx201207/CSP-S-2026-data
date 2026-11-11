#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,mid;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
	}
	mid=(n+1)/2;
	for(int i=1,j=n;(i<=mid)&&(j>=mid);)
	{
		if(b[i]==b[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i]; 
				i++;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				sum+=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				sum+=a[i]; 
				i++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
