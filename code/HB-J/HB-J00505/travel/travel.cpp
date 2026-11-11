#include <bits/stdc++.h>
using namespace std;
int a,aa,b,bb;
char aw,bw;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>aw>>b>>bb>>bw;
    if(a==b)
    {
        cout<<1;
        if(aa==bb)
        {
            cout<<1;
            if(aw>bw)swap(aw,bw);
            if((aw>='A'&&aw<='C'&&bw>='A'&&bw<='C')||(aw>='D'&&aw<='F'&&bw>='D'&&bw<='F'))
            {
                cout<<1;
                if((aw=='A'&&bw=='B')||(aw=='B'&&bw=='C')||(aw=='D'&&bw=='F'))
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
