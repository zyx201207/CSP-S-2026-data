#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c1!="16")
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
