#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=0,b=0,c=0,d=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
            {
                cout<<1;
                if(((s1[2]-'0')-(s2[2]-'0')==1&&(s1[2]-'0')-(s2[2]-'0')==-1))
                {
                    cout<<1;
                }
                else cout<<a;
            }
            else cout<<a<<b;
        }
        else cout<<a<<b<<c;
    }
    else cout<<a<<b<<c<<d;
    return 0;
}
