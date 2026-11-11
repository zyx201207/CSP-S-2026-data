#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000006];
struct node{
    long long dir,step;
};
bool bfs(long long start,long long ending){
    long long cnt=0,short_road=INT_MAX;
    queue<node> q;
    q.push({start,0});
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(cur.dir==ending){
            if(cur.step<short_road){
                short_road=cur.step;
                cnt=1;
            }else if(cur.step==short_road)cnt++;
            continue;
        }
        for(long long i=cur.dir+1;i<=ending;i++){
            if(x[i]-x[cur.dir]>d)break;
            q.push({i,cur.step+1});
        }
    }
    return (cnt==2);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>x[i];
        }
        long long ans=0;
        for(long long u=1;u<n;u++){
            for(long long v=u+1;v<=n;v++){
                ans+=bfs(u,v);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
