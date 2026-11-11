#include <bits/stdc++.h>
using namespace std;
char a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    cout<<b/10<<d/10;
    if(a==c)
    {
        cout<<1;
        if((b/10)==(d/10))
        {
            cout<<1;
            if((b%10=='A'&&d%10=='B')||(b%10=='A'd%10=='C')||(b%10=='B'&&d%10=='A')||(b%10=='B'd%10=='C')||(b%10=='C'&&d%10=='A')||(b%10=='C'd%10=='B')||(b%10=='D'&&d%10=='F')||(b%10=='F'd%10=='D'))
            {
                cout<<1;
                if((b%10=='A'&&d%10=='B')||(b%10=='B'd%10=='A')||(b%10=='B'&&d%10=='C')||(b%10=='C'd%10=='B')||(b%10=='D'&&d%10=='F')||(b%10=='F'd%10=='D'))
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<00;
            }
        }
        else
        {
            cout<<000;
        }
    }
    else
    {
        cout<<0000;
    }
    return 0;
}
