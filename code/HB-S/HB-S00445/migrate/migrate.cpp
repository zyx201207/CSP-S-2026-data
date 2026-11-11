#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[5005];
int f[5005];
int num[5005];
int ans;
struct node{
    int fr,id,x;
};
void bfs(int s){
    queue<node> q;
    q.push({0,s,0});
    num[s]=1;
    num[0]=1;
    while(!q.empty()){
        int p=q.front().id;
        int u=q.front().x;
        int v=q.front().fr;
   //     cout<<p<<' '<<u<<' '<<v<<'\n';
        q.pop();
        if(f[p]!=-1){
            if(f[p]==u)num[p]+=num[v];
            continue ;
        }
        f[p]=u;
        num[p]=num[v];
  //      cout<<p<<' '<<num[p]<<'\n';
        for(int i=p+1;i<=n;i++){
            if(a[i]-a[p]>d)break ;
            q.push({p,i,u+1});
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){

            memset(f,-1,sizeof(f));
            bfs(i);
      //      cout<<i<<'\n';
      //      for(int j=i+1;j<=n;j++){
      //          cout<<f[j]<<' '<<num[j]<<'\n';
     //       }
            for(int j=i+1;j<=n;j++){
                if(f[j]==-1)break ;
                if(num[j]==2)ans++;
            }

        }
        cout<<ans<<'\n';
    }
    return 0;
}
