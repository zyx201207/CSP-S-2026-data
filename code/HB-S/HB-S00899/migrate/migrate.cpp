#include<bits/stdc++.h>
using namespace std;

int c,t,n,m,a[1000005],l[1005][1005],st,ans[1005][1005];
void dfs(int now,int sum){
    if(l[st][now]>sum){
        ans[st][now]=1;
        l[st][now]=sum;
    }
    else if(l[st][now]==sum) ans[st][now]++;
    else return;
    for(int i=now+1;i<=n;i++){
        if(a[i]-a[now]>m) break;
        dfs(i,sum+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        memset(l,0x3f,sizeof(l));
        memset(ans,0x3f,sizeof(ans));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            st=i;
            dfs(i,0);
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(ans[i][j]==2) sum++;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}


