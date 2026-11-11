#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    ll a,b;
    for(int i=0;i<2;i++)
    {
        a=a*10+c1[i]-'0';
        b=b*10+c2[i]-'0';
    }
    ll c,d;
    char e,f;
    for(int i=0;i<3;i++)
    {
        if(i==2)
        {
            e=s1[i];
            f=s2[i];
        }
        else
        {
            c=c*10+s1[i]-'0';
            d=d*10+s2[i]-'0';
        }
    }
    if(a==b)
    {
        cout<<1;
        if(c==d)
        {
            cout<<1;
            if((e>='A'&&e<='C'&&f>='A'&&f<='C')||((e=='D'||e=='F')&&(f=='D'||f=='F')))
            {
                cout<<1;
                if(abs(e-f)==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    return 0;
}
