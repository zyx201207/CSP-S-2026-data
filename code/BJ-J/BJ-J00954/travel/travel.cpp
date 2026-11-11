#include <bits/stdc++.h>
using namespace std ;
bool check1(string a,string b)
{
    for (int i=0 ; i<=1 ; i++)
    {
        if (a[i]!=b[i])
        {
            return false ;
        }
    }
    return true ;
}
bool check2(string a,string b)
{
    if ((a[2]>='A'&&a[2]<='C'&&b[2]>='D'&&b[2]<='F')||(b[2]>='A'&&b[2]<='C'&&a[2]>='D'&&a[2]<='F')||a[2]=='C'&&b[2]=='D'||a[2]=='D'&&b[2]=='C')
    {
        return false ;
    }
    return true ;
}
bool check3(string a,string b)
{
    if (abs(a[2]-b[2])==1||a[2]=='F'&&b[2]=='D'||a[2]=='D'&&b[2]=='F')
    {
        return true ;
    }
    return false ;
}
int main ()
{
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    string a,b,c,d ;
    cin >> a>>b>>c>>d ;
    if (a==c)
    {
        cout << 1 ;
    }
    else
    {
        cout << 0;
    }
    if (a==c&&check1(b,d))
    {
        cout << 1 ;
    }
    else
    {
        cout << 0 ;
    }
    if (a==c&&check1(b,d)&&check2(b,d))
    {
        cout << 1 ;
    }
    else
    {
        cout << 0 ;
    }
    if(a==c&&check1(b,d)&&check2(b,d)&&check3(b,d))
    {
        cout << 1;
    }
    else{
        cout << 0 ;
    }
    return 0 ;
}
