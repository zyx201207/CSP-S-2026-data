#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    string r1=s1.substr(0,2);
    string x1=s2.substr(0,2);
    if(r1==x1) cout<<"1";
    else
    {
        cout<<"000";
        return 0;
    }

    char r2=s1[2];
    char x2=s2[2];
    if(r2<='C'&&x2<='C')
    {
        int r=r2-'A',x=x2-'A';
        if(abs(r-x)==1) cout<<"11";
        else cout<<"10";
    }
    else if(r2>='D'&&x2>='D') cout<<"11";
    else cout<<"00";
    return 0;
}