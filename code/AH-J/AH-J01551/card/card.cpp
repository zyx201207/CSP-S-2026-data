#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100];
int b[100];
int s[100];
int ans;
cin>>a;
for(int i=1;i<=a;i++)
{
cin>>b[i];
for(int j=1;j<=a;j++)
{

s[i]=(b[j]&&b[j+1};
for(int l;l<a;l++)
{
if(s[l]>s[l+1])
{
ans=s[l];
else{
ans=s[l+1];
}
}
}
}
}
cout<<ans;
return 0;
}
