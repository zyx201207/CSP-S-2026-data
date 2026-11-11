#include<bits/stdc++.h>
using namespace std;
int n;
long long s,a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1,j=n;i<j;)
	{
		if(b[i]!=b[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				s+=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				s+=a[i];
				i++;
			}
		}
		else
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
	}
	cout<<s;
	return 0;
} 
