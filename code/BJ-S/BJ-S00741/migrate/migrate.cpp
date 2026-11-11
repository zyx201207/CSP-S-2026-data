#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2e6+26;
ll testid,_,n,d,u,ans;
ll a[MAXN],nxt[MAXN],dist[MAXN],cnt[MAXN];
bool vis[MAXN];
queue<ll> que;
void solve1(){
    ans=0;
    cin>>n>>d;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1,j=1;i<=n;i++){
        j=max(i,j);
        while(j<n&&a[j+1]-a[i]<=d) j++;
        nxt[i]=j;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            dist[j]=0;
            cnt[j]=0;
            vis[j]=false;
        }
        que.push(i);
        cnt[i]=1;
        vis[i]=true;
        while(!que.empty()){
            u=que.front();
            que.pop();
            for(ll v=u+1;v<=nxt[u];v++){
                if(!vis[v]){
                    dist[v]=dist[u]+1;
                    cnt[v]=cnt[u];
                    vis[v]=true;
                    que.push(v);
                }
                else if(dist[v]==dist[u]+1){
                    if(cnt[u]!=-1) cnt[v]+=cnt[u];
                    if(cnt[v]>2) cnt[v]=-1;
                }
            }
        }
        for(ll j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
    }
    cout<<ans<<'\n';
    return;
}
void solve2(){
    ans=0;
    cin>>n>>d;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1,j=1;i<=n;i++){
        j=max(i,j);
        while(j<n&&a[j+1]-a[i]<=d) j++;
        nxt[i]=j;
    }
    if(nxt[1]>=3) ans=max(n-2*nxt[1]+3,0ll);
    cout<<ans<<'\n';
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>testid>>_;
    while(_--){
        if(testid<=6) solve1();
        else if(testid==11||testid==12) solve2();
        else solve1();
    }
    return 0;
}
/*
ting yu de sheng yin, yi di di qing xi, ni de hu xi xiang yu di shen ru wo de ai li. zhen xi wang yu neng xia bu ting
hui ying de.
yi qi feng fa a, lao shi
*/