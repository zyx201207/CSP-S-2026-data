#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    char n,a1,a2,b1,b2,c1,c2;
    cin>>n>>a1;
    cin>>n>>b1>>c1;
    cin>>n>>a2;
    cin>>n>>b2>>c2;
    if(a1==a2)
    {
        cout<<1;
        if(b1==b2)
        {
            cout<<1;
            if(c1=='A'&&c2=='B'||c1=='B'&&c2=='C'||c1=='D'&&c2=='E'
               ||c1=='B'&&c2=='A'||c1=='C'&&c2=='B'||c1=='E'&&c2=='D')
            {
                cout<<"11";
            }
            else if(c1=='A'&&c2=='C'||c1=='C'&&c2=='A')
            {
                cout<<"10";
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
