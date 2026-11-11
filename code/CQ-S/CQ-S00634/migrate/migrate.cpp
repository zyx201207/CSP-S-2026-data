#include <bits/stdc++.h>
#define ll long long
using namespace std;
int C,T;
ll rd(){
    #ifdef LOCAL_WINDOWS
    #define getchar _getchar_nolock
    #else
    #define getchar getchar_unlocked
    #endif
    char ch=getchar();
    int flg=0;
    ll x=0;
    while(ch<48||ch>57) flg|=ch=='-',ch=getchar();
    while(ch>47&&ch<58) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return flg?-x:x;
    #undef getchar
}
namespace solve1{
    int n;
    ll a[5005],d;
    pair<int,ll> f[5005][5005];
    map<int,ll> mp;
    void solve(){
        while(T--){
            n=rd(),d=rd();
            for(int i=1;i<=n;i++) a[i]=rd();
            int ans=0;
            for(int i=1;i<=n;i++){
                mp.clear(),mp[0]=1,f[i][i]={0,1};
                int L=i;
                for(int j=i+1;j<=n;j++){
                    while(a[j]-a[L]>d){
                        mp[f[i][L].first]-=f[i][L].second;
                        if(!mp[f[i][L].first]) mp.erase(f[i][L].first);
                        L++;
                    }
                    if(mp.empty()) break;
                    f[i][j]=*mp.begin(),f[i][j].first++,ans+=(f[i][j].second==2);
                    mp[f[i][j].first]+=f[i][j].second;
                }
            }
            printf("%d\n",ans);
        }
    }
};
namespace solve2{
    int n;
    ll a[2000005],d;
    void solve(){
        while(T--){
            n=rd(),d=rd();
            for(int i=1;i<=n;i++) a[i]=rd();
            if(n==1){printf("0\n");continue;}
            ll c=a[2]-a[1];
            if(2*c>d) printf("0\n");
            else{
                ll k=d/c;
                printf("%lld\n",max(0ll,n-(2*k-1)));
            }
        }
    }
};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    C=rd(),T=rd();
    if(C<=10) solve1::solve();
    else if(C<=12) solve2::solve();
    return 0;
}
//48pts by ????51?=????50?