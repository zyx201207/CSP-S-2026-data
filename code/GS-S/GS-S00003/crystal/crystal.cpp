#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
using namespace std;

ll n;
ull ans=0;
ll m,val[500010],cnt[500010];
bool wd=false;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%llu",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
    sort(val+1,val+n+1);
    for(int i=1;i<=n;i++)cnt[i]=val[i]-val[i-1];
    ll k=cnt[1];
    for(int i=2;i<=n;i++)if(cnt[i]!=k)wd=true;
    if(!wd){
        ans=min(m/cnt[1],n);
        printf("llu",ans);
        return 0;
    }
    ull nwm=0,ns=0,maxi=n;
    for(ull i=n-1;i>=1;i--){
        if(maxi<i)i=maxi;
        nwm=nwm+cnt[i+1];
        ns++;
        if(nwm>m){
            nwm-=(cnt[maxi]+cnt[i+1]);
            maxi--;
            ans=max(ns,ans);
            //printf("%llu",ns);
            ns--;
            i++;
        }
        //ans=max(ns,ans);

    }
    printf("%llu",ans);
    return 0;
}