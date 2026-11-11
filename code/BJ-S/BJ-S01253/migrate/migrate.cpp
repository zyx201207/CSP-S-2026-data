#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
long long p[2000010];
long long b[5010];
int sum[5010];
long long d,n;
void dfs(int x,int cnt) {
    if(cnt==b[x]) {
        sum[x]++;
    }
    if(cnt<b[x]) {
        b[x]=cnt;
        sum[x]=1;
    }
    if(x==n) {
        return;
    }
    for(int i=x+1;i<=n;i++) {
        if(abs(a[i]-a[x])<=d) {
            dfs(i,cnt+1);
        }
        else {
            break;
        }
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;

    cin>>c>>t;
    while(t--) {
        cin>>n>>d;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        if(c==11||c==12) {
            d/=abs(a[2]-a[1]);
            if(d>=2&&n-d-d+1>0) {
                cout<<n-d-d+1<<"\n";
            }
            else {
                cout<<0<<"\n";
            }
        }
        else if(c==13||c==14) {
            int cnt,ans=0,prh;
            for(cnt=1;cnt<=n;cnt++) {
                if(abs(a[cnt]-a[1])>d) {
                    cnt--;
                    break;
                }
            }
            prh=cnt;
            p[1]=prh;
            for(int i=2;i<=n;i++) {
                for(;prh<=n;prh++) {
                    if(abs(a[prh]-a[i])>d) {
                        prh--;
                        break;
                    }
                }
                p[i]=prh;
            }
            prh=1;
            for(int i=1;i<=n;i++) {
                ans+=p[i]-p[p[i]-1];
            }
            cout<<ans<<"\n";
        }
        else {
            int ans=0;
            for(int i=1;i<=n;i++) {
                for(int j=i+1;j<=n;j++) {
                    b[j]=1e18;
                    sum[j]=0;
                }
                dfs(i,0);
                for(int j=i+1;j<=n;j++) {
                    if(sum[j]==2) {
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
