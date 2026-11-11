#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n,m,a[MAXN],bit[MAXN][31],trie[MAXN*30+5][2],flag[MAXN*30+5],cnt=1,ans;
void insert(int s){
    int u=1;flag[1]++;
    for(int i=0;i<=30;i++){
        if(!trie[u][bit[s][i]]){
            trie[u][bit[s][i]]=++cnt;
        }
        u=trie[u][bit[s][i]];
        flag[u]++;
    }
}
struct node{
    ll u,dep;
};
void bfs(){
    queue<node> q,q0,q1;
    ll sum=0;
    q.push({1,0});
    while(!q.empty()||!q0.empty()||!q1.empty()){
        node now=q.front();q.pop();
        ll u=now.u;
        if(trie[u][1]){
            sum+=flag[trie[u][1]];
            q1.push({trie[u][1],now.dep+1});
        }
        if(trie[u][0]){
            q0.push({trie[u][0],now.dep+1});
        }
        if(q.empty()){
            while(!q1.empty()){
                q.push(q1.front());q1.pop();
            }
            if(sum>=m){
                while(!q0.empty()){
                    q0.pop();
                }
                ans+=(1<<(30-now.dep));
                sum=0;
                continue;
            }
            while(!q0.empty()){
                q.push(q0.front());q0.pop();
            }
            sum=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];int bt=0;
        while(a[i]){
            bit[i][31-(++bt)]=a[i]&1;
            a[i]>>=1;
        }
    }
    for(int i=1;i<=n;i++){
        insert(i);
    }
    bfs();
    cout<<ans;
    return 0;
}