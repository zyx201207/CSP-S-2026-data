#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> G[300005];
int a[500005];
int cnt[300005];
int use[300005];
bool becomeup(){
    use[a[1]] = 1;
    for(int i = 2;i<=n;i++){
        if(a[i] != a[i-1] && use[i]){
            return 0;
        }
        use[a[i]] = 1;
    }
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        G[a[i]].push_back(i);
    }
    if(becomeup()){
        for(int i = 1;i<=m;i++){
            cout << G[i][G[i].size()-1] << " ";
        }
        return 0;
    }
    if(n <= 10000 && m <= 100000000/n){
        stack<int> s;
        for(int i = 1;i<=n;i++){
            bool have[300005] = {0};
            bool vis[300005] = {0};
            for(int j = i;j<=n;j++){
                if(!have[a[j]]){
                    s.push(a[j]);
                    have[a[j]] = 1;
                }else{
                    while(!s.empty()){
                        if(s.top() == a[j]){
                            break;
                        }else{
                            have[s.top()] = 0;
                            s.pop();
                        }
                    }
                }
            }
            while(!s.empty()){
                vis[s.top()] = 1;
                s.pop();
            }
            for(int i = 1;i<=m;i++){
                if(vis[i]){
                    cnt[i]++;
                }
            }
        }
        for(int i = 1;i<=m;i++){
            cout << cnt[i] << " ";
        }
        return 0;
    }else{
        for(int i = 1;i<=m;i++){
            int last = G[i][G[i].size()-1];
            int flag = 0;
            for(int j = last+1;j<=n;j++){
                for(int k = G[a[j]].size()-2;k>=0;k--){
                    if(G[a[j]][k]<=last){
                        flag = max(flag,G[a[j]][k]);
                    }
                }
            }
            cout << last-flag << " ";
        }
    }
    return 0;
}
