#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
long long dis[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        memset(dis,1e9,sizeof(dis));
        long long n,d;
        cin>>n>>d;
      long long ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) dis[i][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    int flag=1;
                for(int k=i;k<=j;k++){
                    if(k!=i&&x[k]-x[i]<=d) dis[i][k]=1;
                    if(k!=j&&x[j]-x[k]<=d) dis[k][j]=1;

                }
                for(int k=i;k<=j;k++){
                    if(dis[i][j]>dis[i][k]+dis[j][k])  dis[i][j]=dis[i][k]+dis[j][k],flag=1;
                    if(dis[i][j]==dis[i][k]+dis[j][k])  flag++;
                }

                if(flag==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}






