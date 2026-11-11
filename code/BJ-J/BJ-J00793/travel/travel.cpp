#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        b1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            b2=1;
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
            {
                b3=1;
                if((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'))
                {
                    b4=1;
                }
                if((s1[2]=='C'||s1[2]=='B')&&(s2[2]=='C'||s2[2]=='B'))
                {
                    b4=1;
                }
            }
            if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
            {
                b3=1;
                b4=1;
            }
        }
    }
    cout<<b1<<b2<<b3<<b4;
    return 0;
}
