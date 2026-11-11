#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
vector<int> edge[MAXN];
bool ok[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n,k;
int check(){
    int cnt = 0;
    if(k > 2){
        for(int i = 1; i <= n; i++) vis[i] = 0;
        for(int i = 1; i <= n; i++){
            if(!ok[i]) continue;
            if(vis[i]) continue;
            cnt++;
            queue<int> q; q.push(i);
            while(q.size()){
                int nowx = q.front(); q.pop();
                if(vis[nowx]) continue;
                vis[nowx] = 1;
                for(int v : edge[nowx]){
                    if(!vis[v] && ok[v]) q.push(v);
                }
            }
        }
    }
    if(cnt >= 3) return 2000000000;
    else{
        for(int i = 1 ; i <= n; i++) dis[i] = 1000000000,vis[i] = 0;
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(ok[i]) dis[i] = 0,q.push(i); 
        }
        while(q.size()){
            int nowx = q.front(); q.pop();
            if(vis[nowx]) continue;
            vis[nowx] = 1;
            for(int v : edge[nowx]){
                if(dis[v] > dis[nowx] + 1){
                    dis[v] = dis[nowx] + 1; 
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n ;i++) ans = max(ans,dis[i]);
        return ans;
    }
}
int check2(int x,int y){
        for(int i = 1 ; i <= n; i++) dis[i] = 1000000000,vis[i] = 0;
        queue<int> q;
        q.push(x); dis[x] = 0;
        q.push(y); dis[y] = 0;
        while(q.size()){
            int nowx = q.front(); q.pop();
            if(vis[nowx]) continue;
            vis[nowx] = 1;
            for(int v : edge[nowx]){
                if(dis[v] > dis[nowx] + 1){
                    dis[v] = dis[nowx] + 1; 
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n ;i++) ans = max(ans,dis[i]);
        return ans;
}
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++){
        int tmp = edge[i].size();
        for(int j = 1; j <= tmp; j++) edge[i].pop_back();
    }
    for(int i = 1; i < n; i++){
        int u,v; scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int answer = 1000000000;
    for(int i = 0; i < (1 << n); i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) ok[j+1] = 1,cnt++;
            else ok[j+1] = 0;
        }
        if(cnt != k) continue;
        else answer = min(answer,check());
        // if(answer == 1){
        //     for(int j = 1; j <= n; j++) cerr << ok[j]; cerr << endl;
        //     for(int j= 1; j <= n; j++) cerr << dis[j] << " ";
        //     cerr << endl;
        // }
    }
    printf("%d\n",answer);
}
void solve2(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++){
        int tmp = edge[i].size();
        for(int j = 1; j <= tmp; j++) edge[i].pop_back();
    }
    for(int i = 1; i < n; i++){
        int u,v; scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int answer = 1000000000;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            answer = min(answer,check2(i,j));
        }
    }
    printf("%d\n",answer);
}
int check(int mid){
    int l1 = mid;
    int r2 = (n-1) / 2 - mid;
    int delta = 2 * mid - 1;
    return (r2 - l1 + 1) - delta;
}
void solve3(){
    scanf("%d%d",&n,&k);
    int m = (n-1) / 2;
    if(k == n) printf("0\n");
    if(k >= m) printf("1\n");

    int l = 1,r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid) <= k) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n",l);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T; scanf("%d%d",&C,&T);
    if(C <= 3) while(T--) solve();
    if(C == 7) while(T--) solve2();
    if(C == 13 || C == 14) while(T--) solve3();
    return 0;
}