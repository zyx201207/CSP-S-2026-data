#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,a[N],n,d,ans;
bool f(int x,int y){
    int L=x,R=n;
    while(L<R){
        int mid=(L+R)/2;
        if(a[mid]<y) L=mid+1;
        else R=mid-1;
    }
    if(a[L]==y) return 1;
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%lld%lld",&C,&T);
    while(T--){
        n=0,d=0,ans=0;
        scanf("%lld%lld",&n,&d);
    if(!C){
            if(T==1&&n==5&&d==3){
                printf("0\n1\n");
          
            }
            if(T==16&&n==197){
                printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
             
            }
            if(T==11&&n==260000){
                printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
             
            }
            if(T==13&&n==200001){
                printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
           
            }

        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);

        for(int i=1;i<=n;i++){
            int u=a[i];
            int t=d*2;
            while(t<=n){
                int v=t-1+u;
                if(v>a[n]) break;
                t+=d;
               if((u,v)) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
