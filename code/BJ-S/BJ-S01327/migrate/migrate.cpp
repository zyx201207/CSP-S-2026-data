#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int a[N],n,d;
int cnt[N],ans=0;
bool flag[N];
struct node{
    int u,cnt;
};
void bfs(int st){
    queue<node> q;
    q.push({st,1});
    q.push(node{-1,-1});
    memset(flag,0,sizeof flag);
    memset(cnt,0,sizeof cnt);
    while (!q.empty()){
        node t=q.front();
        //cout<<t.u<<' '<<t.cnt<<'\n';
        q.pop();
        if (t.u==-1){
                //cout<<"OHH"<<'\n';
                bool e=1;
            for (int i=1;i<=n;i++){
                if (cnt[i]){
                    if (cnt[i]==2&&!flag[i]) ans++;
                    flag[i]=1;
                    e=0;
                    q.push({i,cnt[i]});
                    cnt[i]=0;
                }
                /*
                if (cnt[i]==2&&!flag[i]){
                    ans++;
                    //cout<<st<<' '<<i<<'\n';
                    flag[i]=1;
                }
                else if (cnt[i]) flag[i]=1;
                cnt[i]=0;
                */
            }
            q.push({-1,-1});
            if (e==1) return;
            //memset(cnt,0,sizeof cnt);
        }
        else{
            int u=t.u;
            for (int i=u+1;i<=n;i++){
                if (a[i]-a[u]>d) break;
                if (flag[i]) continue;
                //q.push(i);
                cnt[i]+=t.cnt;
            }
            //for (int i=1;i<=n;i++) cout<<cnt[i]<<' ';
            //cout<<'\n';
        }
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,q;
    cin>>c>>q;
    while (q--){
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        for (int i=1;i<=n;i++) bfs(i);
        cout<<ans<<'\n';
    }
    return 0;
}
