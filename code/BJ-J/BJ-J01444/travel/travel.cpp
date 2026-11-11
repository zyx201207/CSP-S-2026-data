#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    bool fx=false;
    if(c1==c2)
    {
        cout<<1;
        fx=true;
    }
    else{
        cout<<0;
    }
    int ss1=10*(s1[0]-'0')+s1[1]-'0';
    int ss2=10*(s2[0]-'0')+s2[1]-'0';
    bool lo=false;
    if(ss1==ss2&&fx)
    {
        cout<<1;
        lo=true;
    }
    else{
        cout<<0;
    }
    int sa=s1[2]-'A';
    int sb=s2[2]-'A';
    bool p=false;
    if((sa<=2&&sb<=2)|| (sa>=3&&sb>=3)&&fx)
    {
        if(lo)
        {
            cout<<1;
            p=true;
        }
        else cout<<0;

    }
    else cout<<0;
    int ans=sa-sb;
    if(abs(ans)==1&&sa!=2&&sb!=3&&fx&&p)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}