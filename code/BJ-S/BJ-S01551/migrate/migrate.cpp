#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000010],dp[310][310],cnt[310][310];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        if(c<=6){
            int ans=0;
            cin>>n>>d;
            for(int i=1; i<=n; i++){
                cin>>a[i];
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dp[i][j]=1e9;
                    cnt[i][j]=0;
                }
            }
            for(int i=1; i<=n; i++){
                cnt[i][i]=1;
                dp[i][i]=0;
                for(int j=i+1; j<=n; j++){
                    for(int k=j-1; k>=i; k--){
                        if(a[j]-a[k]>d)break;
                        if(dp[i][j]>dp[i][k]+1){
                            dp[i][j]=dp[i][k]+1;
                            cnt[i][j]=cnt[i][k];
                        }else if(dp[i][j]==dp[i][k]+1){
                            cnt[i][j]+=cnt[i][k];
                            if(cnt[i][j]>1e9)cnt[i][j]=1e4;
                        }
                    }
                    if(cnt[i][j]==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }else if(c>=11 && c<=12){
            cin>>n>>d;
            for(int i=1; i<=n; i++){
                cin>>a[i];
            }
            int gc=a[2]-a[1];
            int s=d/gc;
            int ans=0;
            if(s==1){
                cout<<0<<'\n';
                continue;
            }
            if(s==0){
                cout<<0<<'\n';
                continue;
            }
            for(int i=1; i<=n; i++){
                if(i+2*s-1<=n)ans++;
                else break;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
