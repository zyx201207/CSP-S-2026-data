#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+100;
int c,t;
int n,d;
int a[N];
int ans;
bool vis[N];
int minn=1e12+100;
int cd;
bool isin(int x,int ed){
    return 1<=x&&x<=ed;
}

void dfs(int sx,int d,int ex){
    if(sx==ex){
        if(cd<=minn){
            minn=cd;
            ans++;
            //cout<<"ans:"<<ans<<"sx:"<<sx<<"ex:"<<ex<<endl;
        }
        return ;
    }
    vis[ex]=0;
    vis[sx]=0;
    for(int i=1;i<=d;i++){
        int nx=sx+i;
        if(!vis[nx]&&isin(nx,ex)){
            vis[nx]=1;
            dfs(nx,d,ex);

        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;

    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int aans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                memset(vis,0,sizeof(vis));
                minn=1e12+100,cd=0;
                ans=0;
                dfs(a[i],d,a[j]);
                if(ans==2)aans++;

            }

        }cout<<aans<<endl;
        //cout.flush();

    }
    return 0;
}
