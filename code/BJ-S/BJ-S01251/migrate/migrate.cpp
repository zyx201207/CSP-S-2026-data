#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d,x[2000005],mindist,mint,ans;//mindist=最小距离，mint=最短路径出现次数
auto dfs(int u,int v,long long dist){
    if(u==v){
        if(dist<mindist){
            mindist=dist;
            mint=1;
            return;
        }
        if(dist==mindist){
            mint++;
            return;
        }
        return;
    }
    if(x[u+1]-x[u]>d)return;
    for(int i=u+1;i<=v;i++){
        if(x[i]-x[u]>d)break;
        dfs(i,v,dist+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        ans=0;
        for(int j=1;j<=n;j++)cin>>x[j];
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        for(int j=1;j<=n-3;j++){
            for(int k=j+3;k<=n;k++){
                mindist=1e9;mint=0;
                dfs(j,k,0);
                if(mint==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
