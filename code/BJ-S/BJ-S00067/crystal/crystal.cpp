#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
long long dis[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    //int st=n;
    long long ans=-1;
    for(int st=n;st>1;st--)
    {
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=st;i++)
            dis[i]=a[st]-a[i];
        sort(dis+1,dis+st+1);
        //for(int i=1;i<=st;i++)
        //    cout<<dis[i]<<" ";
        //cout<<endl;
        long long sum=0,cnt=0;
        for(int i=1;i<=st;i++)
        {
            if(sum+dis[i]<=m)
            {
                sum+=dis[i];
                cnt++;
            }
            else
                break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
