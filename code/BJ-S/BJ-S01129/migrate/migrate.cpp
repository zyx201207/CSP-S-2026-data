#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010],ans;
void solve1()
{
    ans=0;
    for(int l=1;l<=n;l++)
        for(int r=l+1;r<=n;r++)
        {
            int mi=n,cnt=0;
            for(int msk=0;msk<(1<<r-l-1);msk++)
            {
                int lst=l,len=0;
                bool f=true;
                for(int i=l+1;i<r;i++)
                    if((msk>>i-l-1)&1)
                    {
                        if(a[i]-a[lst]>d)
                        {
                            f=false;
                            break;
                        }
                        len++;
                        lst=i;
                    }
                if(a[r]-a[lst]>d) f=false;
                len++;
                if(!f||len>mi) continue;
                if(len<mi) mi=len,cnt=1;
                else cnt++;
            }
            if(cnt==2) ans++;
//                cout<<l<<" "<<r<<" "<<mi<<" "<<cnt<<"\n";
        }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n<=15) solve1();
    }
    return 0;
}
