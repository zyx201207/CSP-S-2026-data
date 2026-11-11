#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,r1,c2,r2;
    char s1,s2;
    cin>>c1>>r1>>s1>>c2>>r2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    else if(r1!=r2)
    {
        cout<<"1000";
        return 0;
    }
    else if(s1<='C'&&s2>'C'||s1>'C'&&s2<='C')
    {
        cout<<"1100";
        return 0;
    }
    else if(abs(s1-s2)>1&&s1!='D'&&s1!='F')
    {
        cout<<"1110";
        return 0;
    }
    else
    {
        cout<<"1111";
        return 0;
    }
}
