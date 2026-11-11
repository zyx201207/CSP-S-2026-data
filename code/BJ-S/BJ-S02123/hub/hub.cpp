
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
queue<int>q;
vector<int>edge[1000005];
int dist[1000005][2];int dp[1000005];
int fur;int l,r;int c,t;int d;
bool vis[1000005];int n,k;
void bfs(int s,int val){
    fur=0;
    q.push(s);
    while(!q.empty()){
        int k=q.front();
        fur=(dist[k][val]>dist[fur][val])?k:fur;
        vis[k]=1;
        q.pop();
        for(auto &a:edge[s]){
            if(!vis[a]){
                q.push(a);
                dist[a][val]=dist[k][val]+1;
            }
        }
    }

}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        if(k==n){
            cout<<0<<endl;
            continue;
        }
        if(k==n-1){
            cout<<1<<endl;
            continue;
        }
        if(k==n-2){
            cout<<2<<endl;
            continue;
        }
    }
}
