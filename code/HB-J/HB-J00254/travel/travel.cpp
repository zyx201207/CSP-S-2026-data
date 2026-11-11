#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==c)
    {
        cout<<1;

        string s1=b.substr(0,2);
        string s2=d.substr(0,2);
        if(s1==s2)
        {
            cout<<1;

            char x=b[2];
            char y=d[2];
            if(x=='A'&&y=='B')
            {
                cout<<"11";
                return 0;
            }
            if(x=='A'&&y=='C')
            {
                cout<<"10";
                return 0;
            }
            if(x=='A'&&y=='D')
            {
                cout<<"00";
                return 0;
            }
            if(x=='A'&&y=='F')
            {
                cout<<"00";
                return 0;
            }

            if(x=='B'&&y=='A')
            {
                cout<<"11";
                return 0;
            }
            if(x=='B'&&y=='C')
            {
                cout<<"11";
                return 0;
            }
            if(x=='B'&&y=='D')
            {
                cout<<"00";
                return 0;
            }
            if(x=='B'&&y=='F')
            {
                cout<<"00";
                return 0;
            }

            if(x=='C'&&y=='B')
            {
                cout<<"11";
                return 0;
            }
            if(x=='C'&&y=='A')
            {
                cout<<"10";
                return 0;
            }
            if(x=='C'&&y=='D')
            {
                cout<<"00";
                return 0;
            }
            if(x=='C'&&y=='F')
            {
                cout<<"00";
                return 0;
            }

            if(x=='D'&&y=='F')
            {
                cout<<"11";
                return 0;
            }
            if(x=='D'&&y=='A')
            {
                cout<<"00";
                return 0;
            }
            if(x=='D'&&y=='B')
            {
                cout<<"00";
                return 0;
            }
            if(x=='D'&&y=='C')
            {
                cout<<"00";
                return 0;
            }

            if(x=='F'&&y=='D')
            {
                cout<<"11";
                return 0;
            }
            if(x=='F'&&y=='A')
            {
                cout<<"00";
                return 0;
            }
            if(x=='F'&&y=='B')
            {
                cout<<"00";
                return 0;
            }
            if(x=='F'&&y=='C')
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
