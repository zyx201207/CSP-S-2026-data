#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[3001000];
int bfs(int s){
    int vis[n+2],us[n+2];
    for(int i=1;i<=n;i++){
        vis[i]=us[i]=-1;
    }
    vis[s]=0;
    queue<int>q;
    q.push(s);
    int res=0;
    while(q.size()){
        int f=q.front();q.pop();
        for(int i=f+1;i<=n;i++){
            if(x[i]-x[f]>d)break;
            if(vis[f]+1==vis[i]&&us[i]==-1){
                res++;
                us[i]=1;
                continue;
            }else if(vis[f]+1==vis[i])continue;
            if(-1!=vis[i])continue;
            if(vis[i]==-1){
                vis[i]=vis[f]+1;
                q.push(i);
                if(us[f]==1){
                    res++;
                    us[i]=1;
                }
                continue;
            }
        }
    }
    return res;
}
int query(int x,int y){
    return x-(x/y);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c<=10){
            int ans=0;
            for(int i=1;i<=n;i++){
                ans+=bfs(i);
            }
            cout<<ans<<'\n';
        }else if(c<=12){
            int ans=0,cnt=x[2]-x[1];
            cnt=ceil(1.0*d/cnt);
            for(int i=1;i<=n;i++){
                if(i+cnt>n){
                    break;
                }
                ans+=query(n,cnt)-query(i,cnt)-(cnt-i%cnt-1);
            }
            cout<<ans<<'\n';
        }else if(c<=16){

        }else{
            while(1){
                cout<<"";
            }
        }
    }
    cout<<endl;
    return 0;
}

