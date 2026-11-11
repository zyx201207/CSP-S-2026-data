#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,x[5005];
long long a[5005][5005],cnt[5005][5005];
int ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        sort(x+1,x+1+n);
        for(int i=1;i<=n;i++){
            int L=i,R=i,c=1;
            a[i][i]=0;
            cnt[i][i]=1;
            for(int j=i;j<=n;j++){
                while(L<j&&x[j]-x[L]>d){
                    if(L<=R){
                        c-=cnt[i][L];
                    }
                    L++;
                }
                while(R+1<j&&a[i][R+1]<=a[i][L]){
                    if(L<=R+1){
                        c+=cnt[i][R+1];
                    }
                    R++;
                }
                if(i==j) continue;
                a[i][j]=a[i][L]+1;
                cnt[i][j]=c;
                if(cnt[i][j]==2){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
