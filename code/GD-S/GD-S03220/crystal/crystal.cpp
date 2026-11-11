#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long n,m,a[N],z=0,s=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int r=1,l=1;r<=n;r++)
	{
		z+=(r-l)*(a[r]-a[r-1]);
		for(;l<=n&&z>m;l++)
		{
			z-=(a[r]-a[l]);
		}
		s=max(s,r-l+1ll);
		//cout<<l<<' '<<r<<"\n";
	}
	cout<<s;
}
