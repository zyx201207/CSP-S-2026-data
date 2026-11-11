#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000001],ans,cf[2000001],cnt[2000001],qz[2000001],minn[2000001];
void dfs(int now,int cost){
    if(cost>minn[now]){
        return;
    }
    if(cost<minn[now]){
        minn[now]=cost;
        cnt[now]=1;
    }
    else{
        cnt[now]++;
    }
    for(int nex=now+1;nex<=n;++nex){
        if(qz[nex-1]-qz[now-1]>d){
            break;
        }
        dfs(nex,cost+1);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
        }
        for(int i=1;i<n;++i){
            cf[i]=x[i+1]-x[i];
        }
        for(int i=1;i<n;++i){
            qz[i]=qz[i-1]+cf[i];
        }
        for(int i=1;i<=n;++i){
            memset(minn,0x3f,sizeof minn);
            memset(cnt,0,sizeof cnt);
            dfs(i,0);
            for(int j=i+1;j<=n;++j){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
