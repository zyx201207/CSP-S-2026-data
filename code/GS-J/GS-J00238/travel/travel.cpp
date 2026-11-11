#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout);
    string  s,z ;
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
            if(c1='1'||c1='16'||c2='1'||c2='16')
            {
                    return 0 ;
            }
            if(c1!=c2)
            {
                cout << 0000;
            }
            if(c1==c2&&s1!=s2)
            {
                cout << 1000 ;
            }
            if(c1==c2&&s1==S2&&s='A'&&z='C'||s='C'&&z='A')
            {
                    cout << 1110
            }
            if(c1==c2&&s1==S2&&abs(s-z)==1||abs(z-s)==1&&s=='A'&&z=='B'||s=='B'&&z=='C'|||s=='C'&&z=='D'||s=='B'&&z=='A'||s=='C'&&z=='B'|||s=='D'&&z=='C')
            {
                    cout << 1111 ;
            }


        return 0 ;


}
