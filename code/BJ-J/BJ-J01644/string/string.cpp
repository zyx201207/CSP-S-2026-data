#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

long long a[200005];
char c[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    long long l=0;
    string s;
    long long maxn=-1e9;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        maxn=max(maxn,a[i]);
        l+=a[i];
    }
    if(maxn*n>=1000000000)
    {
        printf("%lld",l/2);
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    long long cnt=0;
    for(long long i=0;i<=l/2-1;i++)
    {
        if(s[i]!=s[n-i+1])
        {
            cnt++;
        }
    }
    printf("%lld",cnt);
    return 0;
}
