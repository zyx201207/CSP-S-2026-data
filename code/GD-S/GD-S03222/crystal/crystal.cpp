#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],tmp,h=1ll,t=1ll,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    while(h<=n)
    {
        tmp=s[h]-s[t-1];tmp=a[h]*(h-t+1)-tmp;
        if(tmp<=m)
		{
			ans=max(ans,h-t+1);
			h++;
		}
        else t++;
    }
    printf("%lld",ans);
    return 0;
}
