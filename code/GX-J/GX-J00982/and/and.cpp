#include<bits/stdc++.h>
using namespace std;

long long n,m,p[100000],mx,nx;
long long b,c,d;




long long math(long long o)
{
    int  a;
    while (1)
    {
        if(o/2==0) break;
        a=o/2;
        o=o%2;

        return o;
    }
}




int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    for(int i=0;i<n;i++)
    {
        cin >> p[i];}



    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
        {
            nx=math(p[i]);
            mx=max(mx,p[i]);
        }
    }
    cout << mx;

    return 0;
}
