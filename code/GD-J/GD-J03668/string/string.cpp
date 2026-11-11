#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005],s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		mx=max(mx,a[i]);
	}
	if(mx<=50)
	{
		int pos=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s[++pos]=c[i];
			} 
		}
		int cnt=0;
		for(int i=1;i<=pos/2;i++)
		{
			if(s[i]==s[pos+1-i])
			{
				cnt++;
			}
		}
		cout<<pos/2-cnt<<endl;
	}
	else cout<<0<<endl;
	return 0;
} 
