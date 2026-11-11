#include <bits/stdc++.h>
using namespace std;
#define int long long
int cid,t,n,D,a[2000010];
int to[2000010];
int dis[5002],cnt[5002],sz[5002];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cid>>t;
    while(t--){
        cin>>n>>D;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i;j>=1;j--){
                if(a[i]-a[j]<=D) to[i]=j;
                else break;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                dis[j]=1e18,cnt[j]=0,sz[j]=0;
            }
            dis[i]=0,cnt[i]=1,sz[0]=1;
            int M=0;
            int r=i;
            for(int j=i+1;j<=n;j++){
                if(max(to[j],i)>r){
                    while(r<max(to[j],i)){
                        sz[dis[r]]-=cnt[r];
                        if(!sz[dis[r]]) M++;
                        r++;
                    }
                }
                dis[j]=M+1;
                cnt[j]=sz[dis[j]-1];
                sz[dis[j]]+=cnt[j];
            }
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
