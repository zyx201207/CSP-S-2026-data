#include<bits/stdc++.h>
using namespace std;
const int MAXN=500;
int c,t,n,d,ans;
int a[MAXN],G[MAXN][MAXN],zd[MAXN][MAXN],zdl[MAXN][MAXN];
void dfs(int f,int x,int ui){
    for(int i=1;i<=n;i++){
        if(G[x][i]==1){
            if(ui+1<zdl[f][i]){
                zdl[f][i]=ui+1;
            }
            dfs(f,i,ui+1);
        }
    }
}
void dfs11(int f,int x,int ui){
    for(int i=1;i<=n;i++){
        if(G[x][i]==1){
            if(ui+1==zdl[f][i]){
                zd[f][i]++;
            }
            dfs(f,i,ui+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int yuio=1;yuio<=t;yuio++){
        ans=0;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            memset(G[i],0x3f,sizeof(G[i]));
            memset(zd[i],0,sizeof(G[i]));
            memset(zdl[i],0x3f,sizeof(G[i]));
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    G[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n-1;i++){
            dfs(i,i,0);
        }
        for(int i=1;i<=n-1;i++){
            dfs11(i,i,0);
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(zd[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

