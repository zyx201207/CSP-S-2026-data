#include <bits/stdc++.h>
using namespace std;
struct node
{
    int c;
    char s[10];
};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    node a,b;
    cin>>a.c>>a.s>>b.c>>b.s;
    if(a.c==b.c)
    {
        if(a.s[0]==b.s[0]&&a.s[1]==b.s[1])
        {
            if(a.s[2]<='C'&&b.s[2]<='C'||a.s[2]>='D'&&b.s[2]>='D')
            {
                if(a.s[2]+1==b.s[2]||a.s[2]-1==b.s[2])
                {
                    cout<<1111;
                }
                else
                {
                    cout<<1110;
                }
            }
            else
            {
                cout<<1100;
            }
        }
        else
        {
            cout<<1000;
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}