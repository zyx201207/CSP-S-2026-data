#include <bits/stdc++.h>

using namespace std;
int n,m;
long long cnt;
int a[200005],cho[200005],s=1,ma;
bool vis[200005];
/*
queue<pair<int,int>> q;
void bfs(int x,int cnt){
    if(cnt==m){
        cout<<ans;
    }
    while(!q.empty()){
        pair<int,int> p=q.front();
        if(!vis[p.first] && )
    }
}
void dfs(int x,int cnt){
    if(cnt==m){
        cout<<max(ans,ma);
        return;
    }
    ma=cho[0];
    for(int i=1;i<cnt;i++){
        ma=ma&cho[i];
    }
    ans=max(ans,ma);
    dfs(x+1,cnt);
    dfs(x+1,cnt+1);
    cho[cnt+1]=a[x+1];
}*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //dfs(0,0);
    for(long long i=LONG_MAX;i>=0;i>>1){
        if(cnt==m){
            cout<<ma;
            return 0;
        }
        if(i&1){
            s&=a[i];
            cnt++;
            ma=max(ma,s);
        }

    }
    return 0;
}
