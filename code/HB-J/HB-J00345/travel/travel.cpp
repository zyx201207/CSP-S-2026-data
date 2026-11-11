#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1=s1)
    {
        cout<<"11";
    }
    else
    {
        cout<<"00";
    }
    if(s1=s2)
    {
        cout<<"11";
    }
    else
    {
        cout<<"00";
    }
    return 0;
}
