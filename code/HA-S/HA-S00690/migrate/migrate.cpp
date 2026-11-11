#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t;
const int N=324092;
long long a[N];
int main()
{
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	}
	while(t--)
	{
		if(*a%2==0)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
