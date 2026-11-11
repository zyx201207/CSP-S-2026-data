#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000010],ans;
struct node{
    int x,dis,cnt;
    friend bool operator<(node x,node y){
        return x.dis>y.dis;
    }
}top;
priority_queue<node>q[2];
int sol(int st){
    int res=0;
    for(int i=0;i<2;i++)while(q[i].size())q[i].pop();
    for(int i=st,val,cnt,now,pre;i<=n;i++){
        now=i&1,pre=now^1,val=0,cnt=1;
        while(q[pre].size())q[pre].pop();
        while(q[now].size()){
            if(x[i]-q[now].top().x<=d){
                top=q[now].top();
                if(top.dis==val)cnt+=top.cnt;
                else if(top.dis<val||val==0)val=top.dis,cnt=top.cnt;
                q[pre].push(top);
            }
            q[now].pop();
        }
        q[pre].push({x[i],val+1,cnt});
        if(cnt==2)res++;
    }
    return res;
}
signed main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout),
    cin.tie(0)->sync_with_stdio(0),cin>>c>>t;
    while(t--){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)ans+=sol(i);
        cout<<ans<<"\n";
    }
}