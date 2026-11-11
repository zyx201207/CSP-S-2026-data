#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],maxx=-1;
char c[200005];
bool ok,ok1;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ok=1,ok1=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(i>1)
		{
			if(c[i]!=c[i-1]) 
			{
				ok=0;
			}
			if(a[i]!=a[i-1])
			{
				ok1=0;
			}
		}
		maxx=max(maxx,a[i]);
	}
	if(ok)
	{
		cout<<0;
		return 0;
	}
	if(ok1)
	{
		cout<<(long long)(n/2*a[1]);
		return 0;
	}
	cout<<maxx;
	return 0;
}
