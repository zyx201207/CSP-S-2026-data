#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char al[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    scanf("%lld",&n);
    string s;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %c",a+i,al+i);
        for(int j=1;j<=a[i];j++)
            s=s+al[i];
    }
    long long sum=s.size();
    for(int i=0;i<sum/2;i++)
        if(s[i]!=s[sum-i-1])
            ans++;
    printf("%lld",ans);
    return 0;
}
