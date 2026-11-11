#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int t1, s1, t2, s2;
    char c1, c2;
    cin>>t1>>s1>>c1>>t2>>s2>>c2;
    if(t1==t2)
    {
        cout<<1;
        if(s1==s2)
        {
            cout<<1;
            if(c1<='C' && c1>='A' && c2<='C' && c2>='A')
            {
                cout<<1;

            }
            else if((c1=='F' || c1=='D') && (c2=='F' || c2=='D'))
            {
                cout<<1;
            }
            else cout<<0;
            if((c1=='A' && c2=='B') || (c1=='B' && c2=='C') || (c2=='A' && c1=='B') || (c2=='B' && c1=='C') || (c2=='D' && c1=='F') || (c2=='F' && c1=='D')) cout<<1;
            else cout<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;

    return 0;
}
