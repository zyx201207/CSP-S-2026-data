#include<bits/stdc++.h>
using namespace std;
long long n,l,z;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        l+=a;
        for(long long i=1;i<=a;i++) s+=b;
    }
    long long j=0,t=l-1;
    for(long long i=1;i<=l/2;i++)
    {
        if(s[j]!=s[t]) z++;
        t--;
        j++;
    }
    cout<<z;
    return 0;
}
