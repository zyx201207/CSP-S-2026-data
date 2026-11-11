#include<bits/stdc++.h>
using namespace std;
int maxn = -1;
int n,M;
void dfs(vector<int> S,int x,int ans){
    if(x == M){
        maxn = max(ans,maxn);
    }
    if(ans <= maxn)return;
    for(int i = 0;i < S.size();i++){
        if(S[i] != 0){
            int k = S[i];
            S[i] = 0;
            dfs(S,x + 1,ans & k);
            S[i] = k;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> M;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int j;
        cin >> j;
        a.push_back(j);
    }
    dfs(a,0,2147483647);
    cout << maxn;
}