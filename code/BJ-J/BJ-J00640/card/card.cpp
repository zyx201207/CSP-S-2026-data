#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],pos[300005],ans[300005];
vector<int>add[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];pos[a[i]]=i;}
    // for(int i=1;i<=n;i++)cerr<<nxt[i]<<" ";
    for(int i=n;i>=1;i--){
        int j=pos[a[i]];
        if(add[j].size()==0){
            add[i].push_back(a[j]);
            ans[a[j]]++;
            for(auto it:add[j+1]){
                add[i].push_back(it);
                ans[it]++;
            }
            continue;
        }
        for(auto it:add[j]){
            add[i].push_back(it);
            ans[it]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
/*
idea:
1:record last(connection)
2:if answer has a_i,a_i must be the last a_i
*/