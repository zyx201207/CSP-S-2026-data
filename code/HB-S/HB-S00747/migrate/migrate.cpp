#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=302;
int n,a[N],q,f[N][N],d,c,ans=0,u=0,y,p=0,r[N][N];
void dfs(int x,int t){
    //cout<<x<<" ";
    while(t>u or p>2){
        return;
    }
    while(x==y){
        p++;return;
    }
    for(int i=x+1;i<=y;i++){
        while(!r[x][i]){
            return;
        }
        dfs(i,t+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
        ans=0;
        cin>>n>>d;memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                f[i][j]=f[j][i]=1e9;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    f[i][j]=f[j][i]=r[i][j]=1;
                    //cout<<i<<" "<<j<<"\n";
                }
            }
        }
        //cout<<"\n";
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(f[i][k]+f[k][j]<f[i][j]){
                        f[i][j]=f[i][k]+f[k][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                u=f[i][j];y=j;p=0;
                dfs(i,0);
                //cout<<"\n"<<i<<" "<<j<<" "<<p<<"\n";
                if(p==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
