#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],t,l,r;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1;
	r=n;
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				t+=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				t+=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<t;
	return 0;
}

