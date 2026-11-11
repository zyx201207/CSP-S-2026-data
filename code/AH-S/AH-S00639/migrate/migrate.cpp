#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+5;
int c,T;
int n,d;
int ans=0;
int arr[MAXN];
void solve(){
    int suml=0,sumr=0;
    for(int i=1;i<=n-3;i++){
        if(arr[i+2]-arr[i]<=d){
            if(arr[i+3]-arr[i+1]<=d){
                if(arr[i+3]-arr[i]>d){
                    sumr=0;
                    int r=i+4;
                    while((arr[r]-arr[i+1]<=d&&r<=n)){
                        sumr++;
                        r++;
                        //printf("#");
                    }
                    //printf("*");
                    ans+=(suml+1)*(sumr+1);
                }
            }
        }else{
            if(arr[i+1]-arr[i]<=d){
                suml++;
            }else{
                suml=0;
            }
        }
    }
}
signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
        }
        arr[n+1]=1e18+5;
        arr[n+2]=1e18+5;
        if(n<=3){
            printf("0\n");
        }else{
            solve();
            printf("%lld\n",ans);
        }
    }

    return 0;
}
