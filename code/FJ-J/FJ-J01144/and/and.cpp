#include<bits/stdc++.h>
using namespace std;
long long k[100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	if(m==1)
	{
		long long t=-1,a;
		cin>>a;
		while (n--)
		t=max(t,a);
		cout<<t;
	}
	else
	{
		long long b=n/2;
		int t=b;
		while(n--)
		{
			cin>>k[b];
		}
		cout<<k[t];
	}
	return 0;
}