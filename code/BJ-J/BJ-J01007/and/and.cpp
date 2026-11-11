#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans;
int n,m;
int a[N],f[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int k=30;k>=0;k--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]&(1<<k)&&!f[i])cnt++;
        if(cnt>=m)
        {
            ans+=(1<<k);
            for(int i=1;i<=n;i++)
                if(!(a[i]&(1<<k)))f[i]=1;
        }

    }
    printf("%lld",ans);
    return 0;
    fclose(stdin);
    fclose(stdout);
}
