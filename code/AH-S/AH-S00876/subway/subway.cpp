#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long timer[500005];
struct dick{
    long long number;
    long long quan;
};
long long ans = 1000000000000000000;
vector<dick> G[30100];
bool vis[30100];
void dfs(long long start,long long finish,long long cnt){
    if(start == finish){
        ans = min(ans,cnt);
        return;
    }
    if(cnt > ans){
        return;
    }
    for(int i = 0;i<G[start].size();i++){
        if(!vis[G[start][i].number]){
            vis[G[start][i].number] = 1;
            dfs(G[start][i].number,finish,cnt+G[start][i].quan);
            vis[G[start][i].number] = 0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    if(c <= 6){
        for(int i = 1;i<=m;i++){
            cin >> timer[i];
        }
        for(int i = 1;i<=n;i++){
            long long k;
            cin >> k;
            long long a[305];
            for(long long j = 0;j<k;j++){
                int st,ro;
                cin >> st >> ro;
                G[st*100+i].push_back({st*100,ro});
                G[st*100].push_back({st*100+i,ro});
                a[j] = st;
            }
            for(long long o = 0;o<k;o++){
                for(long long p = o+1;p<k;p++){
                    G[a[o]*100+i].push_back({a[p]*100+i,0});
                    G[a[p]*100+i].push_back({a[o]*100+i,0});
                }
            }
        }
        while(q--){
            long long st,fi;
            cin >> st >> fi;
            ans = 1000000000000000000;
            memset(vis,0,sizeof(vis));
            vis[st*100] = 1;
            dfs(st*100,fi*100,0);
            cout << ans+timer[st]+timer[fi] << endl;
        }
    }else{
        for(int i = 1;i<=m;i++){
            cin >> timer[i];
        }
        for(int i = 1;i<=n;i++){
            long long k;
            cin >> k;
            for(long long j = 0;j<k;j++){
                int st,ro;
                cin >> st >> ro;
            }
        }
        while(q--){
            long long st,fi;
            cin >> st >> fi;
            cout << timer[st]+timer[fi] << endl;
        }
    }
    return 0;
}

