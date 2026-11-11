#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,k,a[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long lst=1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        long long prev_lst=lst;
        while(cnt>k-(i-prev_lst)*(a[i]-a[i-1]))
        {
            cnt-=a[i]-a[lst];
            lst++;
        }
        cnt+=(i-prev_lst)*(a[i]-a[i-1]);
        ans=max(ans,i-lst+1);
    }
    printf("%lld",ans);
    return 0;
}
