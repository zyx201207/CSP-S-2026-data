#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000020],l[2000020],dis[5050],f[5050],r[5050],s[5050],c[2000020];
void solve()
{
    int n,d,dd,flag=1,flag1=0;
    cin >>n>>d;
    for (int i=1;i<=n;i++) cin >>a[i],c[i]=0;
    dd=a[2]-a[1];
    for (int i=3;i<=n;i++) if(a[i]-a[i-1]!=dd) flag=0;
    for (int i=1;i<=n;i++) l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a,c[l[i]]++;
    for (int i=1;i<=n;i++) if(a[i]-a[1]<=d&&a[n]-a[i]<=d) flag1=1;
    if(flag1)
    {
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            int rr=upper_bound(a+1,a+n+1,a[i]+d)-a;
            if(rr-1>n||rr<=i+2) continue;
            cnt+=c[rr-2];
        }
        cout<<cnt<<"\n";
        return;
    }
    if(dd*2>d&&flag)
    {
        cout<<"0\n";
        return;
    }
    if(flag)
    {
        int ddd=d/dd,cnt=0;
        for (int i=1;i<=n;i++)
        {
            if(i+2*ddd-1>n) continue;
            cnt++;
        }
        cout<<cnt<<"\n";
        return;
    }
    if(n<=5000)
    {
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            memset(dis,0,sizeof(dis));
            memset(f,0,sizeof(f));
            memset(s,0,sizeof(s));
            f[i]=1;s[i]=1;r[0]=i;
            for (int j=i+1;j<=n;j++)
            {
                if(l[j]==j) break;
                int lft=max(l[j],i);
                dis[j]=dis[lft]+1;
                f[j]=s[r[dis[j]-1]]-s[lft-1];
                r[dis[j]]=j;
                s[j]=s[j-1]+f[j];
                if(f[j]==2) cnt++;
                //cout<<j<<" "<<l[j]<<" "<<f[j]<<" "<<s[j]<<endl;
            }
        }
        cout<<cnt<<"\n";
        return;
    }
    cout<<"0\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >>t>>t;
    while(t--) solve();
    return 0;
}
