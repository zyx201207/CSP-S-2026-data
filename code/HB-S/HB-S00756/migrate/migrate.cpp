#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
const int INF=1e18+10;
int c,T,n,d,x[N],wy[N][N],mx[N],ans;
int stp[N];
void dfs(int st,int cur,int ed,int ct){
    // if(ct>stp[ed]-stp[st]||ans>2) return;
    if(ct>wy[st][ed]||ans>2) return; 
    if(cur==ed){++ans;return;}
    for(int i=cur+1;i<=ed&&x[i]-x[cur]<=d;++i){
        dfs(st,i,ed,ct+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        memset(x,0,sizeof(x));
        memset(wy,0,sizeof(wy));
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i!=j) wy[i][j]=INF;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=i+1;x[j]-x[i]<=d&&j<=n;++j){
                mx[i]=j;
                wy[i][j]=1;
                wy[j][i]=1;
            }
        }
        // int i=2,cur=1;
        // while(i<=n){
        //     while(x[i]-x[cur]<=d&&i<=n){
        //         stp[i]=stp[cur]+1;
        //         ++i;
        //     }
        //     mx[cur]=i-1,cur=i-1;
        // }
        // for(int i=1;i<=n;++i){
        //     cout<<stp[i]<<" ";
        // }
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    wy[i][j]=min(wy[i][j],wy[i][k]+wy[k][j]);
                }
            }
        }
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=n;++j){
        //         cout<<wy[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        int res=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                ans=0; dfs(i,i,j,0);
                if(ans==2){
                    // cout<<i<<" "<<j<<'\n';
                    ++res;
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}