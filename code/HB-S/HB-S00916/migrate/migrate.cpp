#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
long long x[310],dis[310][310],ans[310][310];
void floyd(int n){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<j;k++){
                //cout<<i<<' '<<k<<' '<<j<<' '<<dis[i][k]<<' '<<dis[k][j]<<' '<<dis[i][j]<<'\n';
                if(dis[i][k]+dis[k][j]==dis[i][j]&&dis[i][j]!=INF)ans[i][j]++;
                if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j],ans[i][j]=1;
                //cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        long long sum=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=310;i++)for(int j=1;j<=310;j++)dis[i][j]=INF,ans[i][j]=1;
        for(int i=1;i<=310;i++)dis[i][i]=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        //for(int i=1;i<=n;i++)cout<<x[i];
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
            if(abs(x[j]-x[i])<=d)dis[i][j]=1;
            //cout<<x[i]<<' '<<x[j]<<' '<<dis[i][j]<<'\n';
        }
        floyd(n);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int p=ans[i][j];
                //cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
                //cout<<p<<'\n';
                if(p==2){
                    sum++;
                }
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
