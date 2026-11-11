#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn=2e5+7;
int n,l,g[maxn<<1],tot;
pair<int,char>a[maxn];
pair<pair<int,int>,char>e[maxn<<1];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        l+=a[i].first;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        g[++tot]={sum+a[i].first};
        g[++tot]=l-sum-a[i].first;
        sum+=a[i].first;
    }
    sort(g+1,g+tot+1);sum=0;int cur=2;tot=unique(g+1,g+tot+1)-g-1;
    for(int i=1;i<=n;i++){
        sum+=a[i].first;
        while(g[cur]<=sum&&cur<=tot){
            e[cur]={{g[cur-1],g[cur]},a[i].second};
            cur++;
        }
    }
    //for(int i=2;i<=tot;i++){
   //     cout<<e[i].first.first<<' '<<e[i].first.second<<' '<<e[i].second<<'\n';
   // }
    int ans=0;
    for(int i=2;i<=(tot+1)/2;i++){
        if(e[i].second!=e[tot-i+2].second)ans+=e[i].first.second-e[i].first.first;
    }
    cout<<ans;
    return 0;
}
