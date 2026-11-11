#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010];
map<long long,int> mp;
int ans=-1;
long long m;
void dfs(long long cnt){
    if(cnt==0){
        return;
    }
    for(int i=1;i<=n;i++){
        mp[a[i]]--;
        a[i]++;
        mp[a[i]]++;
        ans=max(ans,mp[a[i]]);
        dfs(cnt-1);
        mp[a[i]]--;
        a[i]--;
        mp[a[i]]++;
        ans=max(ans,mp[a[i]]);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    dfs(m);
    cout<<ans;
    return 0;
}
