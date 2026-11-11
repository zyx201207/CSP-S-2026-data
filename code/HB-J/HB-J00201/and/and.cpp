#include<bits/stdc++.h>
using namespace std;
int n,m,a[300006];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int s=1;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=n-m+1;i<=n;i++)
{
s=s&a[i];
}
cout<<s;
return 0;
}
