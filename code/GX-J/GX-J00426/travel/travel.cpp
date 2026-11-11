#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    int z=c.size();
    int p=s.size();
    int ba=1,ab=1;
    for(int i=0;i<z;i++)
    {
        if(c[i]!=cc[i])
        {
            cout<<"0000";
            return 0;
        }
    }
    cout<<"1";
    if(s[0]!=ss[0]||s[1]!=ss[1])
    {
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if(s[2]=='A'||s[2]=='B'||s[2]=='C')
    {
        ba=1;
    }
    else
    {
        ba=2;
    }
    if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')
    {
        ab=1;
    }
    else
    {
        ab=2;
    }
    if(ba!=ab)
    {
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(ab==1)
    {
        if(s[2]=='A')
        {
            if(ss[2]=='C')
            {
                cout<<"0";
                return 0;
            }
        }
        if(s[2]=='C')
        {
            if(ss[2]=='A')
            {
                cout<<"0";
                return 0;
            }
        }
    }
    cout<<"1";
    return 0;
}
