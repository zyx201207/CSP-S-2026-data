#include <bits/stdc++.h>
using namespace std;

int c,d,a,b;
char x,y;
bool l=0;

int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin>>c>>a>>x;
    cin>>d>>b>>y;

    if(c==d)
    {
        cout<<'1';
        l=1;
    }else
    {
        cout<<"0";
        l=0;
    }

    if(a==b&&l==1)
    {
        cout<<'1';
    }
     else
    {
        cout<<"0";
        l=0;
    }

    if(x<='C'&&y<='C'&&l==1||x>='D'&&y>='D'&&l==1)
    {
        cout<<'1';
    }
     else
    {
        cout<<"0";
        l=0;
    }

    if(x-y==1&&l==1||y-x==1&&l==1)
    {
        cout<<'1';
    }
     else
    {
        cout<<"0";
    }
    return 0;
}
