#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
bool dd(char a,char b)
{
    if(a>b) swap(a,b);
    return a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='F';
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        a=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            b=1;
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
            {
                c=1;
                if(dd(s1[2],s2[2]))
                {
                    d=1;
                }
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
