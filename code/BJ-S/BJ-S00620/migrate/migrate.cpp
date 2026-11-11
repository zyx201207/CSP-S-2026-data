#include <bits/stdc++.h>
using namespace std;
long long n,d,a[2000007],ans,dist[2000007],cnt[2000007];
void cfs(int idx){
    for(int i=idx;i<n;i++){
        for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
            if(dist[j]>dist[i]+1){
                dist[j]=dist[i]+1;
                cnt[j]=cnt[i];
            }
            else if(dist[j]==dist[i]+1){
                cnt[j]+=cnt[i];
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        scanf("%lld %lld",&n,&d);ans=0;memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            memset(cnt,0,sizeof(cnt));
            memset(dist,0x3f3f3f3f,sizeof(dist));
            dist[i]=0;cnt[i]=1;
            cfs(i);
            for(int j=i;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
