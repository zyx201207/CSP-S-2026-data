#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+9;
int n,m,ans[N],p[N],vis[N];
void work(int t){
    deque<int> q;
    for(int i=t;i<=n;i++){
        //67676767
        if(!vis[p[i]]){
            q.push_front(p[i]);
            vis[p[i]]=1;
        }else{
            while(q.front()!=p[i]){
                vis[q.front()]=0;
                q.pop_front();
            }
        }
    }
    while(!q.empty()){
        ans[q.front()]++;
        q.pop_front();
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        work(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}