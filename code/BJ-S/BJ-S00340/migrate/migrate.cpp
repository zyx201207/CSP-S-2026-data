#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,t;
int n,d;
int a[2000005];
bool vis[2000005];
int cnt[2000005];
int step[2000005];
void dfs(int x,int st){
    if(x>n) return;
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]>d) break;
        if(st+1<step[i]){
            step[i]=st+1;
            cnt[i]=1;
        }else{
            cnt[i]++;
        }
        dfs(i,st+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(a[2]-a[1]==a[3]-a[2]&&a[n]-a[n-1]==a[2]-a[1]){
            int dd=a[2]-a[1];
            if(2*dd<=d&&d<3*dd&&n>=4) cout<<n-3<<endl;
            else cout<<0<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                memset(cnt,0,sizeof cnt);
                memset(step,0x3f,sizeof step);
                dfs(i,0);
                for(int j=1;j<=n;j++){
                    if(cnt[j]==2) ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}