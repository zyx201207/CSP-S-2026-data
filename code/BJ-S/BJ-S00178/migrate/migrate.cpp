#include <bits/stdc++.h>
#define rep(i,s,t) for(long long i=s;i<=t;i++)
using namespace std;
int a[1002],dp[1002],is[12],cntt[12],t,n,m;
void get_dp(int l,int r,int t,int cnt){
    if(t>=r){
        cntt[cnt]++;
        return;
    }
    rep(i,t+1,r){
        if(a[i]-a[t]<=m){
                get_dp(l,r,i,cnt+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t>>t;
    while(t--){
        cin>>n>>m;
        rep(i,1,n){
            cin>>a[i];
        }
        if(n>9){
            cout<<0;
            continue;
        }
        int cnttt=0;
        rep(i,1,n){
            rep(j,i+1,n){
                get_dp(i,j,i,0);
                memset(cntt,0,sizeof(cntt));
                rep(g,1,n){
                    if(cntt[g]!=0&&cntt[g]!=2){
                        break;
                    }
                    else if(cntt[g]==2){
                        cnttt++;
                        break;
                    }
                }
            }
        }
        cout<<cnttt<<endl;
    }
    return 0;
}
