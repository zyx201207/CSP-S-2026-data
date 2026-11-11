#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char p,q;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    p=s1[2];
    q=s2[2];
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
            if(p=='D'||p=='F')
            {
                if(q<'D')
                {
                    cout<<"00";
                    return 0;
                }
                cout<<"11";
                return 0;
            }
            else if(p=='A'||p=='B'||p=='C')
            {
                if(q>'C')
                {
                    cout<<"00";
                    return 0;
                }
                cout<<"1";
                if(abs(p-q)==2)
                {
                    cout<<"0";
                    return 0;
                }
                cout<<1;
                return 0;
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else if(c1!=c2)
    {
        cout<<"0000";
    }
    return 0;
}
