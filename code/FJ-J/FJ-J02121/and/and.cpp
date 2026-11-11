#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],f[100000],s,h=-100000;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
for(int i=1;i<=n;i++)
{
	for(int j =1+i;j<=n;j++)
	{
	f[i]=(a[j]&a[i]);
	s++;
	}
}
for(int i=1;i<=s;i++)
{
    h=max(h,f[i]);
}
cout<<h;
return 0;
}
