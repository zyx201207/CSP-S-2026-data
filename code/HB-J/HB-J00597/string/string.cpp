#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,sum=0;
cin>>n;
string s="";
if(n<=1)
{
cout<<"0";
return 0;
}
if(n==2)
{
cout<<"1";
return 0;
}
long long a[n][2];
for(int i=0;i<n;i++)
{
for(int j=0;j<2;j++)
{
cin>>a[i][j];
}
}
for(int i=0;i<n;i++)
{
s+=a[i][1];
}
for(int i=0;i<s.length()/2;i++)
{
if(s[i]!=s[n-1-i])
{
sum++;
}
}
cout<<sum;
return 0;
}
