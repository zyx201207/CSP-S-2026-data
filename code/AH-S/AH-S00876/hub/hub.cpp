#include<bits/stdc++.h>
using namespace std;
int c,t;
bool vis1[305];
bool vis2[305];
bool vis3[305];
int last[305];
int n,k;
vector<int> G[305];
int ans2 = 0x3f3f3f3f;
int sum = 0x3f3f3f3f;
void realdfs(int start,int finish,int step){
    if(start == finish){
        ans2 = min(ans2,step);
        return;
    }
    for(int i = 0;i<G[start].size();i++){
        vis3[G[start][i]] = 1;
        realdfs(G[start][i],finish,step+1);
    }
    return;
}
void dfs_low(int start){
    for(int i = 0;i<G[start].size();i++){
        vis2[G[start][i]] = 1;
        dfs_low(G[start][i]);
    }
    return;
}
bool dfs(int k){
    int ma = 0;
    for(int i = 1;i<=k;i++){
        if(!vis2[last[i]]){
            dfs_low(last[i]);
            ma++;
        }
    }
    if(ma>2) return 0;
    else return 1;
}
void dfs_long(int k,int l){
    if(l == k && dfs(k)){
            int cnt = 0;
        for(int i = 1;i<=n;i++){
            int ans = 0x3f3f3f3f;
            for(int j = 1;j<=k;j++){
                memset(vis3,0,sizeof(vis3));
                vis3[i] = 1;
                ans2 = 0x3f3f3f3f;
                realdfs(i,last[j],0);
                ans = min(ans,ans2);
            }
            cnt = max(cnt,ans);
        }
        sum = min(sum,cnt);
    }
    for(int i = 1;i<=k;i++){
        if(!vis1[i]){
            vis1[i] = 1;
            last[l] = i;
            dfs_long(k,l++);
            vis1[i] = 0;
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0;i<305;i++){
            G[i].clear();
        }
        for(int i = 1;i<n;i++){
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        sum = 0x3f3f3f3f;
        dfs_long(k,0);
        cout << sum << endl;
    }
    return 0;
}


