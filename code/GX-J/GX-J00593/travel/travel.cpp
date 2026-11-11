#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[17],c2[5],s1[17],s2[5];
    int l,m,f,h;
    cin>>c1>>c2>>s1>>s2;
    for(int i=0;i<=7;++i)
    {
        if(c1[i]==s1[i])
        {
            l==1;
        }
        else
        {
            cout<<"0";
        }
        if(s1[2]==s2[2])
        {
            m==1;
        }
        else
        {
            cout<<"0";
        }
        if(c2[i]==s2[i])
        {
            f==1;
        }
        else
        {
            cout<<"0";
        }
        if(c1[0]==s1[0])
        {
            h==1;
        }
        else
        {
            cout<<"0";
        }
    }
    cout<<l<<m<<f<<h;
    return 0;
}
