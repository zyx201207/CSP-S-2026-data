#include <bits/stdc++.h>
using namespace std ;
long long cnt ;
string s="";
string s_="" ;
int main ()
{
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    int n ;
    cin >> n ;
    for (int i=1 ; i<=n ; i++)
    {
        int a ;
        string c ;
        cin >> a>> c;
        for (int i=1 ; i<=a; i++)
        {
            s+=c ;
        }
    }
    for (int i=s.size()-1 ; i>=0 ; i--)
    {
        s_+=s[i] ;
    }
    long long mid=(s.size()+1)/2-1 ;
    for (int i=0 ; i<=mid ; i++)
    {
        if (s[i]!=s_[i])
        {
            cnt++ ;
        }
    }
    cout << cnt ;
    return 0 ;
}
