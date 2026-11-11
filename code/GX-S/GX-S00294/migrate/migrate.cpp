#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[500];
struct node {
    int cnt;
    long long dis;
}a[500][500];
void dfs(int b,int now,int dis){
    if(a[b][now].dis>dis){
        a[b][now].dis=dis;
        a[b][now].cnt=1;
    }
    else if(a[b][now].dis==dis){
        a[b][now].cnt++;
    }
    for(int i=now+1;i<=n;i++){
        if(x[i]-x[now]<=d){
            dfs(b,i,dis+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){//begin
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    a[i][j].cnt=0;
                    a[i][j].dis=1e18;
                }
            }
            dfs(i,i,0);
            for(int j=i+1;j<=n;j++){
                if(a[i][j].cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
