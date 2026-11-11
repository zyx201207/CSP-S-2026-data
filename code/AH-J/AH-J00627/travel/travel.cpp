#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {

        cout<<1;
        char ch1=s1[2],ch2=s2[2];
        ll p1=(10*(s1[0]-'0')+(s1[1]-'0')),p2=(10*(s2[0]-'0')+(s2[1]-'0'));
        if(p1==p2)
        {
            cout<<1;
            if((ch1<='C' && ch2<='C') || (ch1>='D' && ch2>='D'))
            {
                cout<<"1";
                if(max(ch1,ch2)-min(ch1,ch2)==1)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
