#include<bits/stdc++.h>
using namespace std;
long long l,n,m=0,ans=0;
string a,b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>l>>a;
		for (int j=0;j<l;j++)
		{
			b+=a;
		}
		m+=l;
	}
	for (int i=0;i<(m+1)/2;i++)
	{
		if (b[i]!=b[m-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
