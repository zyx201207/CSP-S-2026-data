#include<bits/stdc++.h>
using namespace std;
int c1,c2,n1,n2;
char z1,z2;string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    n1=(s1[0]-'0')*10+s1[1]-'0';
    n2=(s2[0]-'0')*10+s2[1]-'0';
    z1=s1[2];z2=s2[2];
    if(c1==c2)
    {
        cout<<1;
        if(n1==n2)
        {
            cout<<1;
            if(z1<='C' && z2<='C')
            {
                cout<<1;
                if(abs(z1-z2)==1) cout<<1;
                else cout<<0;
            }
            else if(z1>'C' && z2>'C')
            {
                cout<<"11";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
