#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int c,t;
long long n,d,x[maxn],dis[maxn][maxn],pt[maxn][maxn],l,r,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        r=1;
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=1e7;
                pt[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n && x[j]-x[i]<=d;j++){
                dis[i][j]=1;
                pt[i][j]=1;
                dis[j][i]=1;
                pt[j][i]=1;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][k]+dis[k][j]<dis[i][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        pt[i][j]=pt[i][k]*pt[k][j];
                        if(pt[i][j]>2)pt[i][j]=3;
                    }
                    else if(dis[i][k]+dis[k][j]==dis[i][j]){
                        pt[i][j]+=pt[i][k]*pt[k][j];
                        if(pt[i][j]>2)pt[i][j]=3;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(pt[i][j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
