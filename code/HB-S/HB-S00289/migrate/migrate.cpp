#include <bits/stdc++.h>

using namespace std;
int n;
int ans=0;
void bfs(vector<vector<int>>& grid,int st){
    queue<int> q;
    vector<int> cnt(n+1,0);
    q.push(st);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int i=0;i<grid[f].size();i++){
            cnt[grid[f][i]]++;
            q.push(grid[f][i]);
        }
    }
    for(int i=1;i<cnt.size();i++){
        cout<<cnt[i];
        if(cnt[i]==2)ans++;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    int d;
    while(t--){
        cin>>n>>d;
        vector<int> temp(n+1);
        for(int i=1;i<=n;i++){
            cin>>temp[i];
        }
        vector<vector<int>> grid(n+1);
        int cover;
        for(int i=1;i<=n;i++){
            cover=temp[i]+d;
            int to=lower_bound(temp.begin()+1,temp.end(),cover)-temp.begin()-1;
            for(int j=i+1;j<=to;j++){
                grid[i].push_back(j);
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            bfs(grid,i);
        }
        cout<<ans<<"\n";
    }
}
