#include<bits/stdc++.h> 
using namespace std;
long long int a[200005];
char b[200005];
long long int s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(long long int i=0 , j=0;!(n-j<i);)
	{
		if(b[i]==b[n-j])
		{
			if(a[i]<a[n-j])
		{	
			a[n-j]-=a[i];
			i++;
		}
		else if(a[i]>a[n-j])
		{
			a[i]-=a[n-j];
			j++;
		}
		else
		{	
			i++;
			j++;
		}
		}
		else
		if(a[i]<a[n-j])
		{
			s+=a[i];
			a[n-j]-=a[i];
			i++;
		}
		else if(a[i]>a[n-j])
		{
			s+=a[n-j];
			a[i]-=a[n-j];
			j++;
		}
		else
		{
			s+=a[i];	
			i++;
			j++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
