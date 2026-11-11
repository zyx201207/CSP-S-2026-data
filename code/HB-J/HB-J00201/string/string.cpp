#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a,sum=0;
string b,s;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a>>b;
for(int i=1;i<=a;i++)
{
s+=b;
}
}
for(int i=0;i<=floor(n/2)-1;i++)
{
if(s[i]!=s[i+floor(n/2)])
{
sum++;
}
}
cout<<sum;
return 0;
}
