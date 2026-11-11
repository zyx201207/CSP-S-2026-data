#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2000006;
const ll inf=3e18;
int c,T,n;
ll d,a[N],dis[N],cnt[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++) dis[j]=inf,cnt[j]=0;
            dis[i]=0,cnt[i]=1;
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j-1;k>=i&&a[j]-a[k]<=d;k--)
                {
                    if(dis[j]>dis[k]+1) dis[j]=dis[k]+1,cnt[j]=cnt[k];
                    else if(dis[j]==dis[k]+1) cnt[j]+=cnt[k];
//                    if(cnt[j]>2) break;
                }
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
