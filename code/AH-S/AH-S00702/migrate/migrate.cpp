#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=50005;
LL n,m,T,hyw,a[N],f[N],cnt[N];
void bfs(LL x){
    queue<LL>q;q.push(x);f[x]=0;
    while(!q.empty()){
        LL u=q.front();
        for(LL i=u+1;i<=n;i++){
            if(abs(a[i]-a[u])>m) break;
            if(f[u]+1<f[i]){
                f[i]=f[u]+1;cnt[i]=1;
            }else if(f[u]+1==f[i]) cnt[i]++;
            if(f[u]+1<=f[i]) q.push(i);
        }q.pop();
    }
}int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>hyw>>T;
    while(T--){
        cin>>n>>m;LL ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }LL k=a[2]-a[1],ok=0;
        for(int i=2;i<=n;i++) if((a[i]-a[i-1])!=k) ok=1;
        if(ok==0){cout<<0;continue;}
        for(LL i=1;i<=n;i++){
            memset(f,0x3f,sizeof f);
            memset(cnt,0,sizeof cnt);
            bfs(i);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }cout<<ans<<"\n";
    }
    return 0;
}
