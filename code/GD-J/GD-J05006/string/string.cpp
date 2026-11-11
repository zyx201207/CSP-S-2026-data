#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200000];
char b[200000];
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while (l<=r)
	{
		long long t=0;
		bool k=0;
		if (b[l]!=b[r]) k=1;
		if (a[l]==a[r]) 
		{
			t=a[l];
			r--;
			l++;
		}
		else if (a[l]>a[r])
		{
			t=a[r];
			a[l]-=a[r];
			r--;
		}
		else 
		{
			t=a[l];
			a[r]-=a[l];
			l++;
		}
		if (k==1) sum+=t;
	}
	cout<<sum;
	return 0;
}
