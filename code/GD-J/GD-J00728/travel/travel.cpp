#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    ll p1=(s1[0]*10+s1[1]-(ll)('0'*11)),p2=(s2[0]*10+s2[1]-(ll)('0'*11));
    if(c1==c2)
    {
        cout<<'1';
        if(p1==p2)
        {
            cout<<'1';
            if((s1[2]<='C')==(s2[2]<='C'))
            {
                cout<<'1';
                if(abs(s1[2]-s2[2])==1)cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}