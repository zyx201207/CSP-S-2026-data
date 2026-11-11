#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int w1=0,w2=0,t=0;
    cin>>c1>>s1>>c2>>s2;

    if(s1[2]=='D'||s1[2]=='F') w1=1;
    if(s2[2]=='D'||s2[2]=='F') w2=1;
    if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) t=1;

    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s1[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if(w1==w2)
            {
                cout<<1;
                if(abs(s1[2]-s2[2])==1&&t==0)
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;

    return 0;
}
