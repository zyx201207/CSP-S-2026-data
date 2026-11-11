#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long num[200000],L=0,ans=0;
string s[200000];
long long n;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>num[i]>>s[i];
        L+=num[i];

    }
    long long l=1,x1=1,r=L+1-l,x2=n+1-x1;
    while(x1<x2)
    {

        if(l>num[x1])
        {
            l=1;
            x1++;
        }
        if(L+1-r>num[x2])
        {

            x2--;
            r=L;

        }
        if(s[x1]!=s[x2]) ans++;
        l++;
        r--;
    }
    cout<<ans;

    return 0;
}
