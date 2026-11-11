#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	ll i,j,n,l,r,s=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		char x;
		ll num;
		cin>>num>>x;
		for(j=1;j<=num;j++)
		{
			a+=x;
		}
	}
	r=a.size()-1;
	l=0;
	while(l<r)
	{
		if(a[l]!=a[r])	s++;
		l++;
		r--;
	}
	printf("%lld",s);
	return 0;
}
