#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+8;
int C,t,n,d,a[maxn],dp[maxn][3],pos[maxn];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }//sort(a+1,a+n+1);
        if(d==1){
            cout<<"0\n";
            continue;
        }memset(pos,0,sizeof(pos));
        for(int i=1;i<=n;i++){
            int l=i,r=n,mid;
            while(l<=r){
                mid=l+r>>1;
                if(a[mid]-a[i]<=d)pos[i]=mid,l=mid+1;
                else r=mid-1;
            }
        }
        a[n+1]=a[n+2]=a[n+3]=4e18;
        a[0]=-4e18;pos[0]=1;
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>0;i--){
            if(a[i+1]-a[i]>d){
                dp[i][2]=dp[i][1]=0;
                continue;
            }
            if(a[i+2]-a[i]>d){
                dp[i][2]=dp[i+1][2]*(int)(a[i+1]-a[i-1]>d);
                dp[i][1]=dp[i+1][1]*(int)(a[i+1]-a[i-1]>d);
                continue;
            }
            dp[i][2]=dp[pos[i]][2]+dp[pos[i]-1][1];
            dp[i][1]=dp[pos[i]][1]+pos[i]-pos[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=dp[i][2];
        }
        //for(int i=1;i<=n;i++)cout<<dp[i][1]<<' ';cout<<'\n';
        //for(int i=1;i<=n;i++)cout<<dp[i][2]<<' ';cout<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
