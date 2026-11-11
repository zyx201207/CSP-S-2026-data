#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
typedef long long ll;
const int N=2e6+6;
int x[N],dis[5005][5005],n,T,d;
int f[5005][5005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T>>T;
    while(T--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=i+1;j<=n;j++)dis[i][j]=1e18,f[i][j]=0;
            dis[i][i]=0,f[i][i]=1;
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                int j=i+l-1;
                int mn=1e18;
                for(int k=i+1;k<=j;k++){
                    if(x[k]-x[i]>d)break;
                    mn=min(mn,dis[k][j]);
                }
                dis[i][j]=mn+1;
                for(int k=i+1;k<=j;k++){
                    if(x[k]-x[i]>d)break;
                    if(dis[k][j]==mn)f[i][j]+=f[k][j];
                }
                if(f[i][j]==2)++ans;
                //cout<<f[i][j]<<" \n"[j==n];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

