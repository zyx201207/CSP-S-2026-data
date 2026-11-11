#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[2000005];
bool vis[2000005];
int res,cnt;
void dfs(int u,int v,long long a){
    if(u==v){
        if(a<res){
            res=a;
            cnt=1;
        }
        else if(a==res) cnt++;
        return ;
    }
    for(int i=u+1;i<=v;i++){
        if(x[i]-x[u]>d) break;
        if(!vis[i]){
            vis[i]=1;
            dfs(i,v,a+1);
            vis[i]=0;
        }
    }
}
void query(){
    int b;
    long long sum=0;
    long long k=x[2]-x[1];
    if(d%k==0) b=d/k;
    else b=d/k+1;
    for(int i=1;i<=n;i++){
        if(n-(i+b)+1>0) sum+=n-(i+b)+1;
        else break;
    }
    cout<<sum<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;

        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11 || c==12){
            query();
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=n;j>i+2;j--){
                memset(vis,0,sizeof(vis));
                res=1e9;
                cnt=0;
                vis[i]=1;
                dfs(i,j,0);
                if(cnt==2) ans++;

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
