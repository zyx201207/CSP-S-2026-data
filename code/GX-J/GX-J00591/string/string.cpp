#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int i,n,j,sum=0,a[1000],p=0;
    char s[10000],s1[1000];
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>a[i]>>s1[i];
    }
    for(i=0;i<n;++i)
    {
        if(s1[i]==s1[i+1])
        {
            sum++;
        }
        else
        {
            break;
        }
    }
    if(sum==n-1)
    {
        cout<<0;
    }
    return 0;
}
