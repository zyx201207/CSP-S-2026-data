#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,sum=0;
    cin>>n;
    string s,c;
    for(long long i=0;i<n;i++)
    {
        cin>>a>>c;
        for(long long j=0;j<a;j++)
        {
            s+=c;
        }
    }
    long long r=s.length();
    for(long long i=0;i<r/2;i++)
    {
        if(s[i]!=s[r-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
