#include<bits/stdc++.h>
using namespace std;
int n,m,a,book[2005];
long long ans,f=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int opt=0;
		while(a)
		{
			opt++;
			book[opt]+=a%2;
			a/=2;
		}
	}
	for(int i=1;i<=31;i++)f*=2;
	for(int i=32;i>=1;i--)
	{
		if(m==0)
		{
			cout<<ans;
			return 0;
		}
		if(book[i]>=m)
		{
			ans+=f;
			m--;
		}
		f/=2;
	}
	cout<<ans;
	return 0;
}
