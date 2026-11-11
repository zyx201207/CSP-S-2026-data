#include<bits/stdc++.h>
using namespace std;
const long long N=5010,inf=0x3f3f3f3f;
int n,lst[N];
long long c,T,d,a[N],dis[N],p[N],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c<=6)
        {
            for(int i=1;i<=n;i++)
            {
                long long l=1,r=i,cnt=0;
                while(l<=r)
                {
                    long long mid=(l+r)/2;
                    if(a[mid]>=a[i]-d)
                    {
                        cnt=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                lst[i]=cnt;
            }
            for(int i=1;i<=n;i++)
            {
                memset(dis,0x3f,sizeof(dis));
                dis[i]=0;
                p[i]=1;
                for(int j=i;j<=n;j++)
                {
                    for(int k=max(i,lst[j]);k<j;k++)
                    {
                        if(dis[j]==dis[k]+1) p[j]+=p[k];
                        else if(dis[j]>dis[k]+1) p[j]=p[k];
                        dis[j]=min(dis[j],dis[k]+1);
                    }
                }
                for(int j=i;j<=n;j++) if(p[j]==2) ans++;
            }
            cout<<ans<<endl;
        }
        if(c==11 || c==12)
        {
            int array_d=a[2]-a[1],r=d/array_d;
            for(int i=1;i<=n;i++) if(i+2*r-1<=n && i+2*r-1>i+r) ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}
