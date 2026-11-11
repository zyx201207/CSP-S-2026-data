#include  <bits/stdc++.h>
using namespace std;
int c,t,n,d;
struct Node{
int idx;
int st;
};
vector<int>arr,vec;
vector< vector<int> >mp;
int vis[5005] = {0};
void dfs(int idx,int st,int des){
    if(idx == des){
        arr.push_back(st);
        return;
    }
    for(int k:mp[idx]){
        if(!vis[k]){
            vis[k]=1;
            dfs(k,st+1,des);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        int ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> vec[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(abs(vec[i]-vec[j])<=d && i!=j){
                    mp[j].push_back(i);
                    mp[i].push_back(j);
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                arr.resize(5005,0);
                vec.resize(5005,0);
                memset(vis,0,sizeof(vis));
                dfs(i,0,j);
                if(arr.size()==2&&arr[0]==arr[1]){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
