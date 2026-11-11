#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
long long n,m,a[maxn],l,r,ll,rr,ans;
char c[maxn];
struct xxx
{
    long long x,y,z;
}b[maxn];
void check()
{
    if(l<b[ll].x)ll--;
    if(r>b[rr].y)rr++;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        b[i]={m+1,m+a[i],c[i]};
        m+=a[i];
    }
    l=(m+1)/2,r=(m+2)/2;
    for(int i=1;i<=n;i++)
    {
        if(b[i].x<=l&&l<=b[i].y)ll=i;
        if(b[i].x<=r&&r<=b[i].y)rr=i;
    }
    while(l&&r<=m)
    {
        long long s=min(l-b[ll].x+1,b[rr].y-r+1);
        if(b[ll].z!=b[rr].z)ans+=s;
        l-=s,r+=s,check();
    }
    cout<<ans;
    return 0;
}