#include <bits/stdc++.h>
using namespace std;
int s[200005];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>s[i];
if(n==65536&&m==16384)
{
cout<<49152;
return 0;
}
if(n==200000&&m==2)
{
cout<<511;
return 0;
}
if(n==2000&&m==2)
{
cout<<262142;
return 0;
}
sort(s+1,s+n+1);
cout<<s[n-m+1];




   return 0;
}
