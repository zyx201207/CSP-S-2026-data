#include<bits/stdc++.h> 
using namespace std;
int n,a,sum,num;
string s;
char l;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a>>l;
sum+=a;
for(int j=1;j<=a;j++) s+=l;
}
for(int i=0;i<sum/2;i++)
if(s[i]==s[sum-i-1]) num=num;
else num++;
cout<<num;
return 0;
}
