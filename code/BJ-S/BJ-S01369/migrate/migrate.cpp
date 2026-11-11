#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int n,d;
bool vis[2000005];
/*bool dfs(int x,int y,int cnt,int ans){
    if(x==y){
        return true;
    }
    for(int i=x;a[i]-a[x]<=d;i++){
        if(vis[a[i]])continue;
        vis[a[i]]=1;
        dfs(i,y,cnt+1,ans);
        vis[a[i]]=0;
    }
    return ans>0?true:false;
}
int check(int x,int y){
    int j=x;
    int cnt=1;
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[j]>d){
            j=i;
            cnt++;
        }
    }
    return cnt;
}*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        a[n+1]=LONG_MAX;
        long long cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
