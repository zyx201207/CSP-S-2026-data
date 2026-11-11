#include<bits/stdc+++.h>
using namespace std;

void dfs(int now){
    if(now==y)return;
    for(int i=1;i<=n;i++){
        for(int j=1;k<=k[i];j++){
            if(a[i][j]==now){
                ans2+=w[a[i][j]]+t[i][j];
                for(int p=1;p<=k[i]-j;p++){
                    dfs(a[i][j+p]);
                }

            }

        }
    }
}

int main(){
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=0;i<m;i++)cin>>w[i];
    int k[n];
    int a[3][22],t[3][22];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }

    int ans=0;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans2=0;
        dfs(x);
        ans=min(ans,ans2);
    }
    cout<<ans;
    return 0;

}
