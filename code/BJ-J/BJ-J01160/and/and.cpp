#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[200005],bit[32],choose,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        int cnt=0,temp=a[i];
        while (temp>0)
        {
            bit[cnt++]+=temp%2;
            temp/=2;
        }
    }
    for (int i=31;i>=0;i--)
        if (bit[i]>=m)
        {
            choose=i;
            break;
        }
    sort(a+1,a+n+1,greater<int>());
    int used=0;
    for (int i=1;i<=n;i++)
        if ((a[i]>>choose)%2==1)
        {
            if (ans==0) ans=a[i];
            else ans&=a[i];
            used++;
            if (used==m) break;
        }
    printf("%d",ans);
}
