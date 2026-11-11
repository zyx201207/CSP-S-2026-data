#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200007],ans = 0;
vector<int> k[40];
void dfs(int x,int pre){
    if(x == -1)return;
    long long p = pow(2,x),cnt = 0;
    if(pre == -1){
        for(int i = 1;i <= n;i++){
            if((a[i] & p) != 0){
                cnt++;
                k[x].push_back(i);
            }
        }
    }
    else{
        for(int i = 0;i <= k[pre].size();i++){
            if((a[k[pre][i]] & p) != 0){
                cnt++;
                k[x].push_back(k[pre][i]);
            }
        }
    }
    if(cnt == m){
        ans = a[k[x][0]];
        for(int i = 1;i < k[x].size();i++){
            ans = (ans & a[k[x][i]]);
        }
        return;
    }
    else if(cnt > m){
        dfs(x - 1,x);
        if(ans == 0){
            ans = a[k[x][0]];
            for(int i = 1;i < m;i++){
                ans = (ans & a[k[x][i]]);
            }
        }
        return;
    }
    else{
        dfs(x - 1,pre);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(32,-1);
    cout << ans;
    return 0;
}
