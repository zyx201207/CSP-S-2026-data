#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;
    if(a1==a2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b1==b2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(('A'<=c1&&c1<='C'&&'A'<=c2&&c2<='C')||('D'<=c1&&c1<='F'&&'D'<=c2&&c2<='F'))
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D'))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
