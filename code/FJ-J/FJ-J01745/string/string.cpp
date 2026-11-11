#include<bits/stdc++.h>
using namespace std;
int a[200101];
char b[200101];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long c=0;
	cin>>n;
	for(int i1=1;i1<=n;i1++)
	{
		cin>>a[i1]>>b[i1];
	}
	for(int i1=1,i2=n;i1<i2;)
	{
		if(b[i1]!=b[i2])
			c+=min(a[i1],a[i2]);
		if(a[i1]<a[i2])
			a[i2]-=a[i1],i1++;
		else
		{
			if(a[i1]==a[i2])
				i1++,i2--;
			else
				a[i1]-=a[i2],i2--;
		}
	}
	cout<<c;
	return 0;
}
