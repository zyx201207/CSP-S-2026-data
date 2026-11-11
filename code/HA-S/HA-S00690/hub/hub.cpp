#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t;
const int N=324092;
long long a[N],b[N];
int main()
{
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
	}
	while(t--)
	{
		if(*a%2==0)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
