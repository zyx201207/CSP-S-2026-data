#include<bits/stdc++.h>
using namespace std;
char a,b,c,d,e,f,g,h,i,j;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
    if(a==f&&b==g)
    {
        cout<<1;
        if(c==h&&d==i)
        {
            cout<<1;
            if(((e=='A'||e=='B'||e=='C')&&(j=='A'||j=='B'||j=='C'))||((e=='D'||e=='E')&&(j=='D'||j=='E')))
            {
                cout<<1;
                if(abs((int)(e-'A')-(int)(j-'A'))==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                    return 0;
                }
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
