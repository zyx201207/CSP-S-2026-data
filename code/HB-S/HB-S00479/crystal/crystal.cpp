#include<bits/stdc++.h>
using namespace std;
int n;
long long m,m1,a[500005];
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
int i;
for(i=1;i<=n;i++)
{
	m1=0;
	for(int j=i;j>=1;j--)
	{
		m1+=a[i]-a[j];
	}
	if(m1>m)break;
}
cout<<i-1;
return 0;
}
