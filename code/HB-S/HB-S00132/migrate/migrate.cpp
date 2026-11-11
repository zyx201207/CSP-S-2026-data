#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=2000005;
int a[MAXN];
struct node{
    int id;
    int step;
};
node visit[MAXN];
void solve(){
    memset(a,0,sizeof(a));
    memset(visit,0,sizeof(visit));
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int start=1;start<=n;start++){
        queue<node> q;
        q.push({a[start],0});

        while(!q.empty()){
            node now=q.front();
            q.pop();

            if(now.step<visit[now.id].step||(visit[now.id].step==0&&now.id!=start)){
                visit[now.id]={1,now.step};
            }else if(now.step==visit[now.id].step&&now.id!=start)
                visit[now.id].id++;

            for(int i=now.id+1;i<=n;i++)
                if(a[i]-a[now.id]<=d){
                    q.push({i,now.step+1});
                }else
                    break;
        }

        for(int i=start+1;i<=n;i++)
            if(visit[i].id==2)
                ans++;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}