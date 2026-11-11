#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t, n;
ll d, x[2000005], ans;
ll island(int a,int b)
{
    if(x[b]-x[a]<=d) return 1;
    ll sum=0, minm=2e18+5;
    for(int i=1;x[a+i]-x[a]<=d;i++) for(int j=1;x[b]-x[b-j]<=d&&a+i<=b-j;j++) minm=min(minm,(x[b-j]-x[a+i])/d+((x[b-j]-x[a+i])%d>0?1:0));
    if(minm==0) for(int i=1;x[a+i]-x[a]<=d;i++) for(int j=1;x[b]-x[b-j]<=d&&a+i<=b-j;j++) if(a+i==b-j) sum++;
    else for(int i=1;x[a+i]-x[a]<=d;i++) for(int j=1;x[b]-x[b-j]<=d&&a+i<=b-j;j++) if((x[b-j]-x[a+i])/d+((x[b-j]-x[a+i])%d>0?1:0)==minm) sum+=island(a+i,b-j);
    return sum;
}
void mig()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(island(i,j)==2) ans++;
    cout << ans << endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--) mig();
    return 0;
}
