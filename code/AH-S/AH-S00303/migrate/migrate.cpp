/*
仅有两种走法可以到达
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t;
ll p[N],f[305][305];
ll n,d;
struct migrate{
    ll mn;
    map<ll,int> m;
}a[305][305];
bool vis[305];
void dfs(int st,int u,ll step){
    a[st][u].mn=min(a[st][u].mn,step);
    a[st][u].m[step]++;
    vis[u]=true;
    //cout<<u<<"\n";
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(abs(p[i]-p[u])<=d) dfs(st,i,step+1);
    }
    vis[u]=false;
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ll cnt=0;
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        if(n<=9){
            for(int i=1;i<=n;i++){
                memset(vis,0,sizeof(vis));
                for(int j=i+1;j<=n;j++) a[i][j].mn=0x3f3f3f3f3f3f3f3f,a[i][j].m.clear();
                vis[i]=true;
                dfs(i,i,0);
                for(int j=i+1;j<=n;j++){
                     //cout<<a[j].mn<<" "<<a[j].m[a[j].mn]<<" ";
                     if(a[i][j].m[a[i][j].mn]==2) cnt++;
                }
            }
            cout<<cnt<<"\n";
        }else{//Floyd?
            memset(f,0x3f,sizeof(f));
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][i]=0,a[i][j].mn=0x3f3f3f3f3f3f3f3f,a[i][j].m.clear();
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(abs(p[i]-p[j])>d) continue;
                        if(abs(p[k]-p[i])>d||abs(p[k]-p[j])>d) continue;
                        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                        a[i][j].mn=min(a[i][j].mn,f[i][j]);
                        a[i][j].m[f[i][k]+f[k][j]]++;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(a[i][j].m[a[i][j].mn]==2) cnt++;
                }
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}
