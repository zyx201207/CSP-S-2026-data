#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int c,t;
int n,d;
int a[2000005],len[2000005],val[2000005];

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        int ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        int p=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]-a[1]<=d)continue;
            while(a[i]-a[p+1]>d&&p<i-1)p++;
            if(p==i-1)continue;
            for(int j=i;j>p;j--)
            {
                len[j]=1;
                val[j]=1;
            }
            int r=i-1;
            for(int j=p;j>=1;j--)
            {
                while(r>j&&a[r]-a[j]>d)r--;
                if(r==j)break;
                len[j]=len[r]+1;
                val[j]=0;
                for(int k=r;k>j;k--)
                {
                    if(len[k]!=len[r])break;
                    if(val[j]==3)break;
                    val[j]+=val[k];
                    if(val[j]>3)val[j]=3;
                }
                if(val[j]==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
}
//rp++
