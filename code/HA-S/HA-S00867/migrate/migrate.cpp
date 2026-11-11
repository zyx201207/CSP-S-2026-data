#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll c,t,n,d,x[2000009];
int far[2000009],cls[2000009],dis[2000009],maxdis=0,tot=1,ans;
char num[2000009];
int main(){
    freopen("migrate2.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(;t--;){
        memset(far,0,sizeof(far));
    memset(cls,0,sizeof(cls));

        ans=0;
        scanf("%lld%lld",&n,&d);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        far[0]=1;
        cls[n+1]=n;
        for(ll i=1;i<=n;i++){
            far[i]=far[i-1];
            for(;far[i]<n&&x[far[i]+1]<=x[i]+d;far[i]++);
        }

        for(ll i=n;i>=1;i--){
            cls[i]=cls[i+1];
            for(;cls[i]>1&&x[cls[i]-1]>=x[i]-d;cls[i]--);
            //
        }
        //("\n");
        for(ll i=1;i<=n;i++){
            memset(far,0,sizeof(far));
            for(ll j=i+1;j<=far[i];j++){
                num[j]=1;
            }
            for(ll j=i+1;i<=n;i++){
                dis[j]=dis[max((ll)cls[j],i)]+1;
                if(dis[j]>dis[j-1]){
                    maxdis=j-1;
                }
                for(ll k=cls[j];dis[k]<dis[j]&&k<j;k++){
                    if(num[k]==1){
                        num[j]++;
                        if(num[j]>2){
                            break;
                        }
                    }
                    else{
                        num[j]=3;
                        break;
                    }
                }
                if(num[j]==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
