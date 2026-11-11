#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,cnt=0,l=0,lx=0;
	cin>>n;
	long long a[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	char r[l+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			lx++;
			r[lx]=c[i];
		}
	}
	for(int i=1;i<=l/2;i++)
	{
		if(r[i]!=r[l+1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
