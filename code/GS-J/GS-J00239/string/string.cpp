#include <bits/stdc++.h>
using namespace std;
int  main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long c,a;
    string s="",v;
    cin>>c;
    while(c--)
    {
        cin>>a>>v;
        while(a--)s+=v;
    }
    long long l=s.size(),n=0;
    for(long long i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-1-i])n++;
    }
    cout<<n;
    return 0;
}

