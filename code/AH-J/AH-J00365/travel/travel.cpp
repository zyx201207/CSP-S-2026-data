#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    else
    {
        cout<<1;
        string p1,p2;
        for(int i=0;i<=1;i++)
        {
            char x=s1[i];
            char y=s2[i];
            p1=x+p1;
            p2=y+p2;
        }
        if(p1!=p2)
        {
            cout<<0<<0<<0;
            return 0;
        }
        else
        {
            cout<<1;
            char a=s1[2];
            char b=s2[2];
            if((a=='D'||a=='F'&&(b!='D'&&b!='F'))||(b=='D'||b=='F'&&(a!='D'&&a!='F')))
            {
                cout<<0<<0;
                return 0;
            }
            else
            {
                cout<<1;
                int d=int(a-b);
                if(d==1||d==-1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }

        }
    }
    return 0;
}
