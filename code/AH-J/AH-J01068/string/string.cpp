#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200005],c=0;
	int n,t;
	char b[200005];
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		t+=a[i];
	}
	t/=2;
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(b[l]!=b[r])
			{
				c+=a[r];
			}
			l+=1;
		}
		if(a[l]<a[r])
		{
			if(b[l]!=b[r])
			{
				c+=a[l];
			}
			r-=1;
		}
		if(a[l]==a[r])
		{
			if(b[l]!=b[r])
			{
				c+=a[l];
			}
			l+=1;
			r-=1;
		}
	}
	cout<<c;
}
