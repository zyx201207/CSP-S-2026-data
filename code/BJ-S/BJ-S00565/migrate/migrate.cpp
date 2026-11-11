#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int x[N],l1[N],r1[N],dp[N][N],S[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    while(t--){
            memset(dp,0,sizeof(dp));
            int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];

        }for(int i=1;i<=n;++i){
        l1[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
            r1[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            //cout<<l1[i]<<' '<<r1[i]<<endl;
        }
        for(int i=1;i<=n;++i){
                dp[i][i]=1;S[i][i]=0;
        }
        for(int len=2;len<=n;++len){
            for(int l=1;l+len-1<=n;++l){
                int r=l+len-1;
                //cout<<len<<' '<<l<<' '<<r<<endl;
                if(x[r]-x[l]<=d){
                        dp[l][r]=1;S[l][r]=1;
                }
                else if(l1[r]<=r1[l]){
                    dp[l][r]=r1[l]-l1[r]+1;
                    S[l][r]=2;
                }else{
                    int p=2+S[l1[r]][r1[l]];
                    for(int a=l+1;a<=r1[l];++a){
                        for(int b=l1[r];b<r;++b){
                            if(S[l][a]+S[a][b]+S[b][r]==p){
                                ++dp[l][r];
                            }
                        }
                    }
                }
            }
        }
        for(int l=1;l<=n;++l){
            for(int r=l+1;r<=n;++r){
                    //cout<<l<<' '<<r<<' '<<ans<<endl;
                if(dp[l][r]==2) ++ans;
            }
        }
    cout<<ans<<endl;
    }


    return 0;
}
