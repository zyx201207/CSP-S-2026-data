#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6+10;
int c,t,n,D,a[N],d[N],cnt[N];
void dfs(int pos,int dis){
    if(pos>n) return;
    int i=1,far=a[pos+1]-a[pos];
    if(dis==d[pos]) cnt[pos]++;
    if(dis<d[pos]){
        cnt[pos]=1;
        d[pos]=dis;
    }
    while(far<=D){
        dfs(pos+i,far);
        i++;
        far=a[pos+i]-a[pos];
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(d,0x3f,sizeof d);
        memset(cnt,0,sizeof cnt);
        cin>>n>>D;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        dfs(1,0);
        int ans=0;
        for(int i=1;i<=n;++i){
            if(cnt[i]==2) ans++;
        }
        cout<<ans<<endl;
    }


    return 0;
}
