#include<bits/stdc++.h>
using namespace std ;
string a1 , b1 , a2 , b2 ;
long long s[5] ;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1 >> b1 >> a2 >> b2 ;
    if (a1==a2)
    {
        s[1]=1 ;
        if (b1[0]==b2[0] and b1[1]==b2[1])
        {
            s[2]=1 ;
            if (b1[2]=='A' and (b2[2]=='B' or b2[2]=='C') or
                b1[2]=='B' and (b2[2]=='A' or b2[2]=='C') or
                b1[2]=='C' and (b2[2]=='A' or b2[2]=='B') or
                b1[2]=='D' and b2[2]=='F')
            {
                s[3]=1 ;
                if (b1[2]+b2[2]=='A'+'B' or b1[2]+b2[2]=='B'+'C' or b1[2]+b2[2]=='D'+'F')
                    s[4]=1 ;
            }

        }
    }
    cout << s[1] << s[2] << s[3] << s[4] ;
    return 0 ;
}
