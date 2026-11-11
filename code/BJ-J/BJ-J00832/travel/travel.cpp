#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        a=1;
    }
    else
    {
        cout<<"0";
        a=0;
    }
    if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<"1";
        b=1;
    }
    else
    {
        cout<<"0";
        b=0;
    }
    if(b==1&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')))
    {
        cout<<"1";
        c=1;
    }
    else
    {
        cout<<"0";
        c=0;
    }
    int m=(s1[0]-'0')*10+(s1[1]-'0'),n=(s2[0]-'0')*10+(s2[1]-'0');
    if(a==1&&(c==1&&(s1[2]-1==s2[2]||s1[2]+1==s2[2])))
    {
        cout<<"1";
    }
    else if(a==1&&(s1[2]==s2[2]&&(m-1==n||m+1==n)))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }

    return 0;
}
