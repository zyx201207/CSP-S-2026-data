#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <math.h>
long long a[2000000],y=0,m,n,x=0;
char c[2000000],s[2000000000];
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long i,j;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        cin>>c[i];
        for(j=0;j<a[i];++j)
        {
            s[x]=c[i];
            x++;
        }
    }
    m=x-1;
    for(i=0;i<x;++i)
    {
        if(s[i]!=s[m])
        {
            y++;
        }
        m--;
    }
    cout<<y/2;
    return 0;
}
