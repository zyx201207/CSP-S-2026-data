#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long x,y;
    string a,b;
    cin>>x>>a>>y>>b;
    if(x!=1&&x!=16&&y!=1&&y!=16)
    {
        if(x==y)
        {
            cout<<1;
        }
        else
        {
            cout <<0;
            cout <<0;
            cout <<0;
            cout <<0;
            return 0;
        }
    }
    else
    {
        cout <<0;
        cout <<0;
        cout <<0;
        cout <<0;
        return 0;
    }
    long long c=a[0]*10+a[1];
    long long d=b[0]*10+b[1];
    if(c==d)
    {
        cout <<1;
    }
    else
    {
        cout <<0;
        cout <<0;
        cout <<0;
        return 0;
    }
    long long e,f;
    if(a[2]=='A'||a[2]=='B'||a[2]=='C')
    {
        e=1;
    }
    else
    {
        e=2;
    }
    if(b[2]=='A'||b[2]=='B'||b[2]=='C')
    {
        f=1;
    }
    else
    {
        f=2;
    }
    if(e==f)
    {
        cout <<1;
    }
    else
    {
        cout <<0;
        cout <<0;
        return 0;
    }
    if(a[2]==b[2]+1||a[2]==b[2]-1)
    {
        cout <<1;
    }
    else
    {
        cout <<0;
    }

    return 0;
}
