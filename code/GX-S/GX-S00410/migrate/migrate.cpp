#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,n,t,a[N],s[5501][45000],minn[5501][45000];
long long m;
void bfs(int p,int l,int sum){
    if(sum<=minn[l][p]){
       minn[l][p]=sum;
    }
    for(int i=p+1;i<=n;i++){
        if(a[i]-a[p]<=m){
            bfs(i,l,sum+1);
        }
    }
}
void dfs(int p,int l,int sum){
    if(sum==minn[l][p]){
    s[l][p]++;
    }
    for(int i=p+1;i<=n;i++){
        if(a[i]-a[p]<=m){
            dfs(i,l,sum+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                minn[i][j]=INT_MAX;
                s[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            bfs(i,i,1);
            dfs(i,i,1);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i][j]==2){
                    ans++;

                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
