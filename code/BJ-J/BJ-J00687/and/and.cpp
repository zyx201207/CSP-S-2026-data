#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
int a[200005];
int ans=0;
void dfs(int i){
    if(v.size()==m){
        int sb=a[v[0]];
        for(int j = 1;j<v.size();j++){
            sb &= a[v[j]];
        }
        ans=max(ans,sb);
    }
    if(i>n){
        return;
    }
    if(v.size()<m){
        v.push_back(i);
        dfs(i+1);
        v.pop_back();
        dfs(i+1);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}


