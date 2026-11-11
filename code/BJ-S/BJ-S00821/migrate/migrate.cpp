#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans;
int x[2000010],dp[2000010];
struct p_111{
    int in,step;
};
inline int bfs(int st,int en){
    int re=0,minn=1e15;
    queue<p_111> que;
    que.push({st,0});
    while(!que.empty()){
        int head=que.front().in;
        int step=que.front().step;
        que.pop();
        if(head==en){
            if(step==minn){
                re++;
            }
            else if(step<minn){
                minn=step;
                re=1;
            }
            continue;
        }
        for(int i=head+1;i<=en;i++){
            if(x[i]-x[head]>d){
                break;
            }
            que.push({i,step+1});
        }
    }
    return re;
}
bool check(int u,int v){
    return bfs(u,v)==2;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
