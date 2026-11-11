//long long
//int             #####
#include<bits/stdc++.h>
using namespace std;
//----------------
int c;
void init(){
    int n,k;
    vector<int>mp[100009];
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int o,max1=0,max2=0;
    for(int i=1;i<=n;i++){
        if(mp[i].size()>mp[o].size()){
            o=i;
        }
    }
    queue<int>q;
    int l[1000009];
    bool dis[1000009];
    for(int i=1;i<=n;i++){
        dis[i]=0;
    }
    //////////
    q.push(o);
    l[o]=0;
    dis[o]=1;
    for(int i=1;i<=k;i++){
        int u=q.front();
        q.pop();

        if(l[u]>max1){
            max2=max1;
            max1=l[u];
        }
        else if(l[u]>max2){
            max2=l[u];
        }

        for(auto v:mp[u]){
            if(!dis[v]){
                q.push(v);
                l[v]=l[u]+1;
                dis[v]=1;
            }
        }
    }
    cout<<max1+max2<<endl;
    return;
}
//----------------
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        init();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
