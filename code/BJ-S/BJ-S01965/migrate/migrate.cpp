#include<bits/stdc++.h>
using namespace std;
long long n,d,a[1010100],f[1010100],ju[1010100],cnt[1010100];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c<=10)
    {
        while(T--)
        {
            memset(f,0,sizeof(f));
            memset(a,0,sizeof(a));
            memset(cnt,0,sizeof(cnt));
            memset(ju,0,sizeof(ju));
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                ju[i]=0;
                cnt[0]=1;
                int l=i;
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j]-a[j-1]>d) break;
                    while(a[j]-a[l]>d)
                    {
                        cnt[ju[l]]-=f[l];
                        l++;
                    }
                    f[j]=cnt[ju[l]];
                    if(f[j]==2) ans++;
                    ju[j]=ju[l]+1;
                    cnt[ju[j]]+=f[j];
                }
                for(int j=1;j<=n;j++) f[j]=ju[j]=cnt[j]=0;
            }
            cout<<ans<<endl;
        }
    }
    else if(c<=12)
    {
        while(T--)
        {
            memset(f,0,sizeof(f));
            memset(a,0,sizeof(a));
            memset(cnt,0,sizeof(cnt));
            memset(ju,0,sizeof(ju));

            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            long long ans=0;
            ju[1]=0;
            cnt[0]=1;
            long long l=1,ll=1e9,rr=0;
            for(long long j=2;j<=n;j++)
            {
                if(a[j]-a[j-1]>d) break;
                while(a[j]-a[l]>d)
                {
                    cnt[ju[l]]-=f[l];
                    l++;
                }
                f[j]=cnt[ju[l]];
            //    cout<<j<<" "<<f[j]<<endl;
              //  if(f[j]>2) break;
                if(f[j]==2)
                {
                    ll=min(ll,j);
                    rr=max(rr,j);
                    ans++;
                }
                ju[j]=ju[l]+1;
                cnt[ju[j]]+=f[j];
            }
            if(ans==0)
            {
                cout<<0<<endl;
                continue;
            }
            for(int j=2;j<=n;j++)
            {
                rr++;
                ll++;
                rr=min(rr,n);
                ll=min(ll,n+1);
                ans+=rr-ll+1;
            }
            cout<<ans<<endl;
        }
    }
    else
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            if(n<=20)
            {
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                ju[i]=0;
                cnt[0]=1;
                int l=i;
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j]-a[j-1]>d) break;
                    while(a[j]-a[l]>d)
                    {
                        cnt[ju[l]]-=f[l];
                        l++;
                    }
                    f[j]=cnt[ju[l]];
                    if(f[j]==2) ans++;
                    ju[j]=ju[l]+1;
                    cnt[ju[j]]+=f[j];
                }
                for(int j=1;j<=n;j++) f[j]=ju[j]=cnt[j]=0;
            }
            cout<<ans<<endl;continue;
            }
            cout<<0<<endl;
        }
    }
    return 0;
}
