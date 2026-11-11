#include<bits/stdc++.h>
using namespace std;
const int MAXLEN=2e6+5;
#define int long long
int n,x[MAXLEN],c,T,dis;

void solve(){
    scanf("%lld%lld",&n,&dis);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    int l=1,r=4,ans=0;
    for(int i=4;i<=n;i++){
        int a=x[i-3],b=x[i-2],c=x[i-1],d=x[i];
        //upd l
        if(i>5){
            bool kk1=(x[i-2]-x[i-4]<=dis),kk2=(x[i-4]-x[i-5]<=dis),kk3=(x[i-2]-x[i-3]<=dis),kk4=(x[i-3]-x[i-5]<=dis);
            if(kk1&&kk2&&kk3&&kk4) l=i-3;
        }
        r=max(r,i);
        while(1){
            bool k1=(x[r+1]-x[r-1]<=dis),k2=(x[r-1]-x[r-2]<=dis),k3=(x[r+1]-x[r]<=dis),k4=(x[r]-x[r-2]<=dis);
            if(k1&&k2&&k3&&k4) break;
            r++;
        }
        if(d-a>dis&&c-a<=dis&&d-c<=dis&&b-a<=dis&&d-b<=dis){
            //printf("%lld %lld\n",ans,l);
            ans+=(l-(i-3)+1)*(r-i+1);
        }
    }
    printf("%lld\n",ans);
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    /*
    if(c==11||c==12){
        while(T--){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            if(x[2]-x[1]>d){
                printf("0\n");
                return ;
            }
            else{

            }
        }
    }
    */
    while(T--) solve();
}
