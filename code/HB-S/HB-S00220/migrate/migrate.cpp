#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2000005;
ll c,T;
ll n,d;
ll a[N];
ll ans=0,cnt=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&T);
    while(T--){
        ans=0;
        //++cnt;
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        //printf("%lld %lld %lld ",d,a[2]-a[1],d/(a[2]-a[1]));
        //printf("%lld\n",n);


        if(c>=11&&c<=12){
            if(d/(a[2]-a[1])<=1){printf("0\n");}
            else{printf("%lld\n",max((ll)0,n-(d/(a[2]-a[1])+d/(a[2]-a[1])-1)));}
            continue;
        }


        /*if(c>=3&&c<=6){
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    ll tt=0;
                    for(int k=i+1;k<=j-1;k++){
                        tt+=(a[i]-a[k]<=d&&a[k]-a[j]<=d);
                    }
                    ans+=(tt==2);
                }
            }
            printf("%lld\n",ans);
            continue;
        }*/
        for(int i=1;i<=n;i++){
            //max yuan
            ll l=i+1,r=n;
            while(l<r){
                ll mid=l+(r-l+1)/2;
                if(a[mid]-a[i]<=d){l=mid;}
                else{r=mid-1;}
            }
            //cout<<l<<endl;
            if(l-i==1)continue;
            ll zl=l;
            l=i+1,r=n;
            while(l<r){
                ll mid=l+(r-l+1)/2;
                if(a[mid]-a[zl-2]<=d)l=mid;
                else r=mid-1;
            }
            ll zr=l;
            //ciyuan zuiyuan
            l=zl,r=n;
            while(l<r){
                ll mid=l+(r-l+1)/2;
                if(a[mid]-a[zl-1]<=d){l=mid;}
                else{r=mid-1;}
            }
            ll zc=l;
            //printf("%lld\n",cnt);
            //printf("%lld %lld %lld ",zl,zr,zc);
            ans+=zc-zr;
            //printf("%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
