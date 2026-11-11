#include<bits/stdc++.h>
using namespace std;
int p=0,q=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        string k1;
        string k2;
        k1=s1[0]+s1[1];
        k2=s2[0]+s2[1];
        char f,j;
        f=s1[2],j=s2[2];
        if(f=='A' || f=='B' || f=='C') p=1;
        else p=0;
        if(j=='A' || j=='B' || j=='C') q=1;
        else q=0;
        if(k1==k2)
        {
            cout<<1;
            if(k1==k2 && p==q)
            {
                cout<<1;
                if((f=='A' && j=='B' )|| (f=='B' && j=='C') ||( f=='D' && j=='F')|| (f=='F' && j=='D')||(f=='C' && j=='B') ||( f=='B' && j=='A'))
                cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
