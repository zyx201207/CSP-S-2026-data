#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=500005;
const ll M1 = 1e18;
ll a[M],ff[M];
ll n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    for(ll i=0;i<M;i++){
        ff[i] = M1;
    }
    scanf("%lld",&n);
    scanf("%lld",&m);
    ff[0] = 0;
    ff[1] = 0;
    //printf("%ld %lld\n",n,m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    //printf("%lld%lld%lld\n",a[n],n,m);
    if(n==1){
        cout<<1;
        return 0;
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(ll mini = 1;mini<=1;mini++){
            ll l = mini-1,r=mini+1,s=a[mini];
            ll f[n+1];
            f[1] = 0;
            for(ll i=2;i<=n;i++){
                if(r>n){
                    f[i] = f[i-1]+s-a[l];
                    l--;
                }

                else if(l<=0){
                    ll kr = (a[r]-s)*(i-1);
                    f[i] = f[i-1] + kr;
                    //cout<<kr<<endl;
                    s=a[r];
                    r++;
                }
                else{
                    ll kr = (a[r]-s)*(i-1);
                    ll kl = s-a[l];
                    if(kl<=kr){
                        f[i] = f[i-1] + kl;
                        l--;
                    }
                    else{
                        s = a[r];
                        f[i] = f[i-1] + kr;
                        r++;
                    }
                }
                //if(mini == 1) ff[i] = f[i];
                ff[i] = min(ff[i],f[i]);

            }
        }
    }
    else{
        for(ll i=2;i<=n;i++){
            ff[i] = ff[i-1]+(a[2]-a[1])*i-(a[2]-a[1]);
        }
    }
    ll maxi = 0;
    for(ll i=1;i<=n;i++){
        //cout<<ff[i]<<endl;
        if(m>=ff[i]) maxi=i;
        else break;
    }

    printf("%lld",maxi);
    return 0;
}
