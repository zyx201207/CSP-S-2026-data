
#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",std.in);
freopen("travel.out","w",std.out);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
cout<<1;
if(c1&&c2)
cout<<1;
if(s1[1]==s2[1]&&s1[2]==s2[2])
{
cout<<1;
if(s1[3]-s2[3])
cout<<1;
}
return 0;
}
