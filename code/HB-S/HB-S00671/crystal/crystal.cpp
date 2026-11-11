#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
bool th(int a,int b)
{
    return a<b;
}
ll n,m;
ll a[500005];
ll dis[500005];
ll ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,th);
    for(int i=2;i<=n;i++)
    {
        ll cnt=0;
        ll num=1;
        for(int j=i-1;j>=1;j--)
        {
            if(((long long)a[i]-a[j])+cnt<=m)
            {
                num++;
                cnt+=(a[i]-a[j]);
            }
            else{
                break;
            }
        }
        dis[i]=num;
        if(num>ans)ans=num;
    }
    printf("%lld\n",ans);
    return 0;
}