#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int c,T,n,k,a[300005],ans,b[300005],vis[300005];
vector<int>mp[300005];
int dfs(int x,int par){
    if(b[x])return b[x];
    if(a[x])return 0;
    int ans=0x67676767;
    for(int i:mp[x]){
        if(i==par)continue;
        ans=min(ans,dfs(i,x)+1);
    }
    if(ans>=0x67676767)return 0x67676767;
    return b[x]=ans;
}
void dfs2(int x){
    vis[x]=1;
    for(int i:mp[x]){
        if(vis[i])continue;
        if(!a[i])continue;
        dfs2(i);
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
            if(i<=k)a[i]=1;
            else a[i]=0;
        ans=0x7fffffff;
        do{
            int tmp=0;
            for(int i=1;i<=n;i++)b[i]=0;
            for(int i=1;i<=n;i++)vis[i]=0;
            for(int i=1;i<=n;i++){
                if(vis[i])continue;
                if(!a[i])continue;
                if((++tmp)>2)break;
                dfs2(i);
            }
            if(tmp>2)continue;
            tmp=0;
            for(int i=1;i<=n;i++)
                tmp=max(tmp,dfs(i,0));
            ans=min(ans,tmp);
            //for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
            //for(int i=1;i<=n;i++)cout<<b[i]<<' ';cout<<endl;
            //cout<<ans<<' '<<endl;
        }while(prev_permutation(a+1,a+n+1));
        cout<<ans<<endl;
    }

    return 0;
}
//g++ hub.cpp -o hub -std=c++14 -Wall -O2