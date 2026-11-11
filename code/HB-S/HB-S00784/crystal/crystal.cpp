#include<bits/stdc++.h>
using namespace std;
long long a[500001],v,w,ma,x;
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	v=1;
	w=1;
	ma=1;
	for(int i=2;i<=n;i++)
	{
		w++;
		x+=(w-v)*(a[w]-a[w-1]);
		while(x>m)
		{
			x-=a[w]-a[v];
			v++;
		}
		ma=max(ma,w-v+1);
	}
	cout<<ma;
	return 0;
}
//good small R
