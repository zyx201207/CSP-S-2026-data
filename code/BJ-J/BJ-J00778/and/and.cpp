#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+9;
int n,m,ans,p[N],dp[(1<<20)];
void dfs(int x,int s,int t){
    if(t==m){
        ans=max(ans,s);
        return;
    }
    if(dp[x]){
        return;
    }
    for(int i=0;i<n;i++){
        //six seven
        if((x&(1<<i)))
            continue;
        dfs(x+(1<<i),(s&p[i]),t+1);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n<=25){
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            dfs((1<<i),p[i],1);
        }
        cout<<ans;
    }else {
        if(m==1){
            for(int i=0;i<n;i++){
                cin>>p[i];
            }
            for(int i=0;i<n;i++){
                ans=max(ans,p[i]);
            }
            cout<<ans;
        }
        if(m==2){
            for(int i=0;i<n;i++){
                cin>>p[i];
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ans=max(ans,(p[i]&p[j]));
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
