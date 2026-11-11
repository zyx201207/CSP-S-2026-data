#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,a[200001],e[501][501],p[501][501];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        int n,kk,l=1,ans=0;
        cin>>n>>kk;
        if(c==11||c==12){
            for(int i=1;i<=n;i++)a[i]=0;
            for(int i=1;i<=n;i++)cin>>a[i];
            int vv=(kk/(a[2]-a[1]))*2;
            if(kk<(a[2]-a[1])*2||n<vv)cout<<"0\n";
            else cout<<n-vv+1<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)p[i][j]=0,e[i][j]=1e17;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=l;j<i;j++){
                if(a[i]-a[j]<=kk)e[i][j]=e[j][i]=1,p[i][j]=p[j][i]=1;
                else l++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i;k<=j;k++){
                    if(e[i][j]>e[i][k]+e[j][k]){
                        e[i][j]=e[j][i]=e[i][k]+e[j][k];
                        p[i][j]=p[j][i]=p[i][k]*p[j][k];
                    }
                    else if(e[i][j]==e[i][k]+e[j][k]&&k!=i&&k!=j)p[i][j]=p[j][i]=p[i][j]+p[i][k]*p[j][k];
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(p[i][j]==2)ans++;
            }
        }cout<<ans<<"\n";
    }
    return 0;
}
