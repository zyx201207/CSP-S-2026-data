#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500010],k=1,w;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(w+(a[i]-a[i-1])*(i-1)<=m)
		{
			w+=(a[i]-a[i-1])*(i-1);
			k=i;
		}
	}
	cout<<k;
	return 0;
}
