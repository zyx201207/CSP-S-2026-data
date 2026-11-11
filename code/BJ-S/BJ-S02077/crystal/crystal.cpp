#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long m,a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)   scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    a[n+1]=1e18;
    int last=1,ans=0;
    long long now=0;
    for(int i=1;i<=n;i++)
    {
        while(now>m&&last<=i)
        {
            now-=(a[i]-a[last]);
            last++;
        }
        //cout << i << " " << last << " " << now << endl;
        if(a[i]!=a[i+1])
        {
            ans=max(ans,i-last+1);
            now+=(a[i+1]-a[i])*1ll*(i-last+1);
        }
    }
    printf("%d\n",ans);
    return 0;
}
