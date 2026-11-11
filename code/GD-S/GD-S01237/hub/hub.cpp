#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
vector<int>e[maxn];
int s,n,k;
int ind[maxn];
vector<int>d;
int vis[maxn];
bool check(int mid){
    return true;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear(),ind[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
            ind[u]++,ind[v]++;
        }
        int maxx=0,pos=0;
        for(int i=1;i<=n;i++){
            if(ind[i]>maxx)maxx=ind[i],pos=i;
            if(ind[i]==1)d.push_back(i);
        }
        s=pos;
        int l=1,r=1000000,ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}