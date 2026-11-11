#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int f=0,s=0,t=0,l=0;
    if(c1==c2)
    {
        f=1;
        if(s1[1]==s2[1]&&s1[0]==s2[0])
        {
            s=1;
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
            {
                t=1;
                if(s2[2]=='A'&&s1[2]=='B'||s2[2]=='B'&&s1[2]=='A'||s2[2]=='C'&&s1[2]=='B'||s2[2]=='B'&&s1[2]=='C'||s2[2]=='D'&&s1[2]=='F'||s2[2]=='F'&&s1[2]=='D')
                {
                    l=1;
                }
            }
        }
    }
    cout<<f<<s<<t<<l;
    return 0;
}
