#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=N*N,qq;
int a[N];
bool vis[N];
int an(int x,int y){
    bool sx[N],sy[N];
    int cnt=0,t1=0,t2=0;
    while(x){
        sx[++t1]=bool(x&1);
        x>>=1;
    }while(y){
        sy[++t2]=bool(y&1);
        y>>=1;
    }
    int q=min(t1,t2);
    for(int i=q-1,s=1;i>=0;i--,s<<=1){
        cnt+=s*(sx[i] && sy[i]);
    }
    return cnt;
}
void dfs(int x,int c){
    if(c==0){
        ans=min(ans,x);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            int _x=an(x,a[i]);
            dfs(_x,c-1);
            vis[i]=0;
        }
    }
}
signed main(){
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        fill(vis+1,vis+n+1,0);
        vis[i]=1;
        dfs(a[i],m);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
