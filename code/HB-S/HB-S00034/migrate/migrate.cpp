#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
#define int long long
int x[N],dist[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,c;
    cin>>c>>t;
    while (t--){
        memset(dist,0x3f,sizeof(dist));
        int n,d,ans=0;
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>x[i];dist[i][i]=0;
        }
        for (int i=1;i<=n;i++){
            int j=i+1;
            while (x[j]-x[i]<=d)dist[i][j]=dist[j][i]=1,j++;
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++){
                int cnt=0;
                for (int k=1;k<=n;k++)
                    if (dist[i][j]==dist[i][k]+dist[k][j]&&k!=i&&k!=j)cnt++;
                if (cnt==2)ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}