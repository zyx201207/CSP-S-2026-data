#include<iostream>
using namespace std;

int main()
{
string c1;
string c2;
string s1;
string s2;
string ans="0000";
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1-'0'==c2-'0')
{
    ans[0]='1';
    if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0')
{
    ans[1]='1';
    if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')
    {
        ans[2]='1';
        if(s1[2]-'1'==s2[2]-'0'||s1[2]+'1'==s2[2]-'0')
        {
            ans[3]='1';
        }
    }
}
}
cout<<ans;
return 0;
}
