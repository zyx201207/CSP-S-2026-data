#include<bits/stdc++.h>
using namespace std;

int x[int(2.1e6)]={};
int vis[int(2.1e6)]={};
int main(){
    int c,t;cin >> c >> t;
    while (t--){
        fill(x, x+int(2.1e6), 0);
        vector<vector<int>>graph(int(2.1e6));
        int n,d;cin >> n >> d;
        for (int i = 0; i<n; i++){
            cin >> x[i];
        }
        int l=0,r=0;
        while(r<n){
            while(x[r]-x[l]>d){
                l++;
            }
            r++;
            for (int i = l; i<r;i++){
                graph[i].push_back(r);
                graph[r].push_back(i);
            }
        }
        // for (int i = 0; i<100;i++){
        //     for (auto x:graph[i])cout<<x<<' ';
        //     cout << "\n";
        // }
            int ans=0;
        for (int i = 0; i<n;i++){
            fill(vis, vis+n, 0);
            queue<pair<int, int>>que;
            que.push({i, 1});
            vis[i]=1;
            while(!que.empty()){
                auto top = que.front();que.pop();
                int topidx=top.first, cnt=top.second;
                for (ch:(graph[topidx])){
                    if (!vis[ch]){
                        que.push({ch, cnt+1});
                    }else{
                        if (cnt==vis[ch]){
                            ans++;
                        }
                    }
                }
            }
        }
            cout<<ans<<endl;
    }
}