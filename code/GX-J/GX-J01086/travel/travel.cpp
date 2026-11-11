#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,b,c=0,d=0;
string s,r;
cin>>a>>s>>b>>r;
if(a==b)
{
    cout<<1;
}
    else cout<<0;
    d=0;
    if(s[0]*10+s[1]==r[0]*10+r[1]&&a==b)
    {
        cout<<1;
d++;
    }
    else cout<<0;
if(((s[2]=='A'&&r[2]=='A')||(s[2]=='A'&&r[2]=='B')||(s[2]=='A'&&r[2]=='C')||(s[2]=='B'&&r[2]=='B')||
           (s[2]=='B'&&r[2]=='C')||(s[2]=='B'&&r[2]=='A')||(s[2]=='C'&&r[2]=='C')||(s[2]=='C'&&r[2]=='A')||(s[2]=='C'&&r[2]=='B')||
           (s[2]=='D'&&r[2]=='F')||(s[2]=='D'&&r[2]=='D')||(s[2]=='F'&&r[2]=='D')||(s[2]=='F'&&r[2]=='F'))&&d==1)

{


                cout<<1;
            c++;



        }
        else cout<<0;
        if((s[2]=='A'&&r[2]=='B')||
                   (s[2]=='B'&&r[2]=='C')||
                    (s[2]=='B'&&r[2]=='A')||
                    (s[2]=='C'&&r[2]=='B')||
                    (s[2]=='D'&&r[2]=='F')&&c==1)
                {
                            cout<<1;


                }
               else cout<<0;
return 0;
}
