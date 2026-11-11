#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<int> g[10005];
        int cnt[100005];
        int mx=0;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            cnt[u]++,cnt[v]++;
            mx=max(mx,max(cnt[u],cnt[v]));
        }
        if(k==1) cout<<"2\n";
        else if(k==2){
            if(mx==1) cout<<"2\n";
            else cout<<"1\n";
        }
        else if(k==3||k==4) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}
