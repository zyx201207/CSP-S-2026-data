#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,c2,c3,c4;
cin>>c1>>c2>>c3>>c4;
if(c1==c3)cout<<1;
else cout<<0;
if(c1==c3)
{
    if(c2[0]==c4[0] && c2[1]==c4[1])cout<<1;
    else cout<<0;
}
else cout<<0;
    if(c1==c3)
    {

        if(c2[0]==c4[0]&&c2[1]==c4[1])
        {
            if(c2[2]=='A'&&(c4[2]=='B'||c4[2]=='C')||c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')||c2[2]=='C'&&(c4[2]=='B'||c4[2]=='A')||c2[2]=='F'&c4[2]=='D'||c2[2]=='D'&&c4[2]=='F')
            {
            cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        else cout<<0;
    }
    else cout<<0;
    if(c1==c3)
    {

        if(c2[0]==c4[0]&&c2[1]==c4[1])
        {
            if(c2[2]=='A'&&(c4[2]=='B'||c4[2]=='C')||c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')||c2[2]=='C'&&(c4[2]=='B'||c4[2]=='A')||c2[2]=='F'&c4[2]=='D'||c2[2]=='D'&&c4[2]=='F')
            {
                if(c2[2]=='A'&&c4[2]=='B'||c4[2]=='A'&&c2[2]=='B'||c4[2]=='B'&&c4[2]=='C'||c2[2]=='B'&&c4[2]=='C'||c2[2]=='F'&&c4[2]=='D'||c2[2]=='D'&&c4[2]=='F')
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
return 0;
}


