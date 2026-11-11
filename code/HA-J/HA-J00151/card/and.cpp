#include<bits/stdc++.h>
using namespace std;
const int N=2e6+109;
long long a[N];
long long n,m;
long long mx;
map<long long ,long long >s;
void f(long long d,long long y)
{
	if(d==m)
	{
		mx=max(mx,y);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0)
		{
			s[i]=1;
			
			f(d+1,y&a[i]);
			
			s[i]=0;
		}		
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f(0,a[i]);
	}
	cout<<mx;
	return 0;
}

