#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],vis[300010],ans[300010];
vector<int>v;
vector<vector<int>::iterator>last;
int main(){
    freopen("card.in","r",stdin),freopen("card.out","w",stdout),
    cin.tie(0)->sync_with_stdio(0),cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        v.clear(),memset(vis,0,sizeof vis);
        for(int j=i;j<=n;j++){
            while(vis[a[j]])vis[*v.rbegin()]=0,v.pop_back();
            v.push_back(a[j]),vis[a[j]]=1;
        }
        for(auto j:v)ans[j]++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i!=m)cout<<" ";
    }
    return 0;
}