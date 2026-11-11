#include<bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;
int a, b, c, d;

signed main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1])
    {
        a=1;
    }
    else
    {
        printf("0000");
        return 0;
    }

    if(s1[0]==s2[0] && s1[1]==s2[1])
    {
        b=1;
    }
    else
    {
        printf("1000");
        return 0;
    }

    if(s1[2]=='A' && (s2[2]=='B' || s2[2]=='C'))
    {
        c=1;
    }
    else if(s1[2]=='B' && (s2[2]=='A' || s2[2]=='C'))
    {
        c=1;
    }
    else if(s1[2]=='C' && (s2[2]=='B' || s2[2]=='A'))
    {
        c=1;
    }
    else if(s1[2]=='D' && s2[2]=='F')
    {
        c=1;
    }
    else if(s1[2]=='F' && s2[2]=='D')
    {
        c=1;
    }
    else
    {
        printf("1100");
        return 0;
    }

    if(s1[2]=='A' && s2[2]=='B')
    {
        d=1;
    }
    else if(s1[2]=='B' && (s2[2]=='A' || s2[2]=='C'))
    {
        d=1;
    }
    else if(s1[2]=='C' && s2[2]=='B')
    {
        d=1;
    }
    else if(s1[2]=='D' && s2[2]=='F')
    {
        d=1;
    }
    else if(s1[2]=='F' && s2[2]=='D')
    {
        d=1;
    }
    else
    {
        printf("1110");
        return 0;
    }
    printf("1111");
    return 0;
}
