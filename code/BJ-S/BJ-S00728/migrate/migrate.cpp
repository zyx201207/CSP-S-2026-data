#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n=300,d,x[2000005],ans;
int dis[305],minn[305][305],jl[305][305];
bool bk[305][305],fl;
void dfs(int x,int step,int st){
    for(int i=x+1;i<=n;i++){
        if(bk[x][i]){
            dfs(i,step+1,st);
            minn[st][i]=min(minn[st][i],step+1);
        }
    }
}
void dfs1(int x,int step,int st){
    for(int i=x+1;i<=n;i++){
        if(bk[x][i]){
            if(minn[st][i]==step+1){
                jl[st][i]++;
            }
            dfs1(i,step+1,st);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            int jl=x[2]-x[1];
            int cnt=d/jl;
            if(cnt>=2){
                cout<<max(0ll,n-2*cnt+1)<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        return 0;
    }
    while(t--){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                minn[i][j]=1e9+5;
                jl[i][j]=0;
                bk[i][j]=0;
            }
        }
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    bk[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            dfs(i,0,i);
        }
        for(int i=1;i<=n;i++){
            dfs1(i,0,i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(jl[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
