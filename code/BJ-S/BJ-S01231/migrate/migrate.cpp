#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int M=5005;
int a[N];
int lst[N];
int cnt[N];
int dis[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c<=10)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                lst[i]=i;
                cnt[i]=1;
                dis[i]=0;
                int Lst=i-1;
                int R=i;
                int sum=0;
                for(int j=i+1;j<=n;j++)
                {
                    int l=i,r=j;
                    int id=j;
                    while(l<=r)
                    {
                        int mid=l+r>>1;
                        if(a[j]-a[mid]<=d)
                        {
                            id=mid;
                            r=mid-1;
                        }
                        else l=mid+1;
                    }
                    lst[j]=id;
                    dis[j]=dis[id]+1;
                    if(lst[j]==j) break;
                    //sum+=cnt[j-1];
                    while(dis[R]<=dis[id]&&R<j)
                    {
                        sum+=cnt[R];
                        R++;
                    }
                    while(Lst<id-1) sum-=cnt[++Lst];
                    //cout<<Lst<<" "<<R-1<<endl;
                    ans+=(sum==2);
                    //cout<<i<<","<<j<<":"<<sum<<" "<<id<<endl;
                    cnt[j]=sum;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
