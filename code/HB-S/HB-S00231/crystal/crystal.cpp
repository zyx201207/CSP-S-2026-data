#include <bits/stdc++.h>

using namespace std;
long a[500005];
long b[500005];
int p[500005];
long long add[500005];
long long now;
int point=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=0;
    long long m;
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%ld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)b[i]=a[i+1]-a[i];
    b[n]=m+1;
    for(int i=1;i<=n;i++)
    {
        now+=b[i];
        long long all=add[i-1]+(p[i-1]+1)*b[i];
        p[i]=p[i-1]+1;
        while(all>m)
        {
            all-=now;
            now-=b[point];
            point++;
            p[i]--;
        }
        add[i]=all;
    }
    for(int i=1;i<=n;i++)ans=max(ans,p[i]);
    printf("%d",ans+1);
}
