#include<bits/stdc++.h>
using namespace std;
int c,t,n;
int v[2000005],minn,ans;
long long d,x[2000005];
void dfs(int s,int e,int cnt){
    if(s>e||cnt>minn)
        return;
    if(s==e){
        v[cnt]++;
        minn=min(minn,cnt);
        return;
    }
    for(int i=s+1;i<=e;i++){
        if(x[i]-x[s]<=d)
            dfs(i,e,cnt+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                minn=2e9;
                memset(v,0,sizeof(v));
                dfs(i,j,0);
                if(minn!=2e9&&v[minn]==2){
                    ans++;
//                    cout<<i<<' '<<j<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
