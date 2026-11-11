#include<iostream>
#include<cstring>
using namespace std;
constexpr int N=2e6+5;
using ll=long long;
ll x[N];
int n,d;
int l0,r0;
bool f[N];
int mnl,cnt;
void dfs(int now){
    if(now>r0){
        if(!f[l0]||!f[r0]) return;
        int last=-1,l=0;
        for(int i=l0;i<=r0;i++) if(f[i]){
            if(last!=-1&&x[i]-x[last]>d) return;
            last=i;
            l++;
        }
        // cout<<"- ";
        // for(int i=1;i<=n;i++){
        //     if(f[i]) cout<<x[i]<<' ';
        // }
        // cout<<'\n';
        if(l<mnl) mnl=l,cnt=1;
        else if(l==mnl) cnt++;
        return;
    }
    f[now]=1;
    dfs(now+1);
    f[now]=0;
    dfs(now+1);
}
void work(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int ans=0;
    for(l0=1;l0<n;l0++){
        for(r0=l0+1;r0<=n;r0++){
            if(x[r0]-x[r0-1]>d) break;
            // cout<<l0<<'-'<<r0<<":\n";
            mnl=2e9;
            dfs(l0);
            if(cnt==2) ans++;
            // if(cnt==2) cout<<"OK\n";
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int c,t;
    for(cin>>c>>t;t;t--) work();
    return 0;
}