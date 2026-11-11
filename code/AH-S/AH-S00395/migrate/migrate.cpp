#include<iostream>
#include<queue>
#include<cstring>
#include<map>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d;
int a[1005];
int dis[1005][1005];
int ans[1005][1005];
map<pair<int,int>,int> t;
vector<int> g[1005];
int res;
int p=0x3f3f3f3f;
void dfs(int x,int ed,int s){
    if(res>2)   return ;
    if(s>p){
        return ;
    }
    if(x==ed&&s<=p){
        p=s;
        res++;
        return ;
    }
    if(x>ed)    return ;
    for(int e : g[x]){
        dfs(e,ed,s+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        t.clear();
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            g[i].clear();
            cin>>a[i];
        }
        for(int l=1;l<=n;l++){
            for(int r=n;r>=l+1;r--){
                if(a[r]-a[l]<=d){
                    g[l].push_back(r);
                }
            }
        }
        int cnt=0;
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                res=0;
                p=0x3f3f3f3f;
                dfs(u,v,0);
                if(res==2)  cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
