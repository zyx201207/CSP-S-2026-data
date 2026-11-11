#include <bits/stdc++.h>

using namespace std;

string a,b,a2,b2;
string s[4];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<4;i++)
    {
        s[i]='0';
    }
    cin>>a>>b>>a2>>b2;
    if(a==a2)
    {
        s[0]='1';
        if(b[0]==b2[0]&&b[1]==b2[1])
        {
            s[1]='1';
            if((b[2]=='C'||b[2]=='D') && (b2[2]=='C'||b2[2]=='D'))
            {
                if('A'<=b[2]<='C' && 'A'<=b[2]<='C')
                {
                    s[2]='1';
                    if(b[2]-b2[2]==1 || b[2]-b2[2]==-1)
                    {
                        s[3]='1';
                    }
                }
                else
                {
                    s[2]='0';
                    s[3]='0';
                }
                if((b[2]=='D'||b[2]=='F') && (b2[2]=='D'||b2[2]=='F'))
                {
                    s[2]='1';
                    s[3]='1';
                }
                else
                {
                    s[2]='0';
                    s[3]='0';
                }
            }
            else
            {
                if('A'<=b[2]<='C' && 'A'<=b[2]<='C')
                {
                    s[2]='1';
                    if(b[2]-b2[2]==1 || b[2]-b2[2]==-1)
                    {
                        s[3]='1';
                    }
                }
                else if((b[2]=='D'||b[2]=='F') && (b2[2]=='D'||b2[2]=='F'))
                {
                    s[2]='1';
                    s[3]='1';
                }
                else
                {
                    s[2]='0';
                    s[3]='0';
                }
            }
        }
        else
        {
            s[1]='0';
        }
    }
    else
    {
        s[0]='0';
    }
    cout<<s[0]<<s[1]<<s[2]<<s[3];
    return 0;
}
