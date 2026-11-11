#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005],dis,ans;
int f[305][305];
char g[305][305][305];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c>=1&&c<=6){
            memset(f,0x3f,sizeof(f));
            for(int i=1;i<=n;i++) f[i][i]=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j-1;k>=i;k--){
                        dis=a[j]-a[k];
                        if(dis>d) break;
                        else f[i][j]=min(f[i][j],f[i][k]+1);
                    }
                }
            }
            memset(g,0,sizeof(g));
            for(int i=1;i<=n;i++) g[0][i][i]=1;
            for(int i=1;i<n;i++){
                for(int j=1;j<=n;j++){
                    for(int k=i+1;k<=n;k++){
                        for(int l=k-1;l>=j;l--){
                            dis=a[k]-a[l];
                            if(dis>d) break;
                            else{
                                g[i][j][k]+=g[i-1][j][l];
                                if(g[i][j][k]>3) g[i][j][k]=3;
                            }
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    f[i][j]=min(n,f[i][j]);
                    if(g[f[i][j]][i][j]==2) ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
}