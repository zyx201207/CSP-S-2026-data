#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int b[20000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long e=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		int u;
		u=c-'a'+1;
		for(int j=1;j<=x;j++)
		{
			b[++e]=u;
		}
	}
	for(long long i=1;i<=(e+1)/2;i++)
	{
		if(b[i]!=b[(e+1-i)]) ans++;
	}
	cout<<ans;
	return 0;
}
