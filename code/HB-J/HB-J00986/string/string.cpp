#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200009],n;
int up=1,down=0,cnt=0;
char b[200009];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(up<(n-down))
	{
		if(a[up]>a[n-down])
		{
			if(b[up]!=b[n-down])
			{
				b[n-down]=b[up];
				cnt+=a[n-down];
			}
			a[up]-=a[n-down];
			down++;
		}
		else if(a[up]<a[n-down])
		{
			if(b[up]!=b[n-down])
			{
				b[up]=b[n-down];
				cnt+=a[up];
			}
			a[n-down]-=a[up];
			up++;
		}
		else if(a[up]==a[n-down])
		{
			
			if(b[up]!=b[n-down])
			{
				b[up]=b[n-down];
				cnt+=a[up];
			}
			up++;
			down++;
		}
	}
	cout<<cnt;
	return 0;
}
