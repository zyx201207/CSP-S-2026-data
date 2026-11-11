#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
int n;ll d,a[N];int jmp[N];
ll dis[N];int sum[N],pre[N],lst[N],nxt[N];
inline void solve(int id){
    for(int i=1;i<=n;i++){
        dis[i]=sum[i]=pre[i]=lst[i]=0;
    }
    dis[id]=0,sum[id]=1,pre[id]=1,lst[id]=id,nxt[id]=id;
    for(int i=id+1;i<=n;i++){
        if(jmp[i]==i){
            for(int j=1;j<=n;j++){
                dis[j]=0x3f3f3f3f3f3f3f3f;
            }
            break;
        }
        dis[i]=dis[max(id,jmp[i])]+1;
        int l=max(id,jmp[i]),r=nxt[lst[l]];
        sum[i]=min(3,pre[r]-pre[l-1]);
        pre[i]=pre[i-1]+sum[i];    
        if(dis[i]==dis[i-1]){
            lst[i]=lst[i-1];
            nxt[lst[i]]=i;
        }else{
            lst[i]=nxt[i]=i;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int p=1;
        for(int i=1;i<=n;i++){
            while(p<=i&&a[i]-a[p]>d){
                ++p;
            }
            jmp[i]=p;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            solve(i);
            for(int j=1;j<=n;j++){
                ans+=(sum[j]==2);
//                cerr<<i<<' '<<j<<' '<<sum[j]<<'\n';
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}