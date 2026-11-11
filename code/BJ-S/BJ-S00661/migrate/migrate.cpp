#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,M=2e6+5;
int c,t,ans;
int n,d;
int x[M],pre[M];
int dp[N],f[N];
int q[M],l=1,r=0,p;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+1+n);
        for(int i=n,j=n+1;i>=1;i--){
            while(j>1&&x[i]-x[j-1]<=d) j--;
            if(x[i]-x[j]<=d){
                pre[i]=j;
            }
        }

        for(int u=1;u<=n;u++){
            memset(dp,0x3f,sizeof(dp));
            memset(f,0,sizeof(f));
            l=1,r=0,p=u;
            dp[u]=0;f[u]=1;
            for(int i=u+1;i<=n;i++){
                while(p<i){
                    while(l<=r&&dp[q[r]]>dp[p]) r--;
                    q[++r]=p;
                    p++;
                }
                while(l<=r&&q[l]<max(pre[i],u)) l++;
                if(l<=r) f[i]=f[q[l]];
                if(l+1<=r&&dp[q[l]]==dp[q[l+1]]){
                    if(l+2<=r&&dp[q[l]]==dp[q[l+2]]){
                        f[i]=3;
                    }
                    else f[i]=f[q[l]]+f[q[l+1]];
                }

                if(f[i]==2) ans++;
                if(l<=r) dp[i]=dp[q[l]]+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}


