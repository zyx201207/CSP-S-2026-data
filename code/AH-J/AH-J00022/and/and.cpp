#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long ans=0;
    for(int i=1;i<=n-m+1;i++)
    {
        long long cnt=a[i];
        for(int j=i+1;j<=i+m;j++)
        {
            cnt&=a[j];
        }
        ans=max(ans,cnt);
    }
    printf("%lld",ans);
    return 0;
}
