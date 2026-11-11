#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    long long d;
    long long l=1;
    long long s;
    char x;
    long long g=0;
    cin>>d;
    for(long long i=0; i<d; i++)
    {
        cin>>s>>x;
        for(long long j=0; j<s; j++)
        {
            a[l]=x;
            l++;
        }
    }
    for(long long i=1; i<=l; i++)
    {
        if(a[i]!=a[l-i])
        {
            g++;
        }
    }
    cout<<g/2;
    return 0;
}
