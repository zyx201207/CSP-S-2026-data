#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n+1,ansl=0,ansr=0;
	while(l<r)
	{
		ansl+=a[l];
		while(ansl>ansr&&l<r)
		{
			if(c[l]!=c[r])
			{
				cnt+=ansr;
			}
			ansl-=ansr;
			ansr=0;
			r--;
			ansr=a[r];
		}
		if(l<r&&c[l]!=c[r])
		{
			cnt+=ansl;
		}
		ansr-=ansl;
		ansl=0;
		l++;
	}
	cout<<cnt;
	return 0;
}
