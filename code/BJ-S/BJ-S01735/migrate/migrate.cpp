#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N0=302,N1=5003,N=2000006;
int c,t,n,d,x[N],cnt[N1][N1][N0],ans;
inline bool check(int l,int r,int k){
    return (x[r]-x[l]>d)&&(x[r]-x[k]<=d)&&(x[k+1]-x[l]<=d)&&(x[k+2]-x[l]>d);
}
void dfs(int i,int j,int k){
    cnt[i][j][k]++;
    for(int r=j+1;x[r]-x[j]<=d&&r<=n;r++){
        dfs(i,r,k+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c<=10){
            ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n;k++){
                        cnt[i][j][k]=0;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                dfs(i,i,0);
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int k=1;
                    while(cnt[i][j][k]==0&&k<=n) k++;
                    if(cnt[i][j][k]==2) ans++;
                }
            }
        }
        else if(c==11||c==12){
            int dd=d/(x[2]-x[1]);
            if(dd<=1||n<2*dd) ans=0;
            else ans=n-2*dd+1;
        }
        else{
            ans=0;
            for(int l=1;l<=n;l++){
                int k=lower_bound(x+1,x+n+1,x[l]+d)-x-1;
                int r=lower_bound(x+1,x+n+1,x[k]+d)-x;
                if(check(l,r,k)) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
