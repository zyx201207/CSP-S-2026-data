#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int s[N],nt[N],o[N],vis[N],ct[N];
vector<int>v[N];
void dfs(int x){
    vis[x]=ct[x];
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i]);
        vis[x]+=vis[v[x][i]];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(o,-1,sizeof(o));
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=n;i>=1;i--){
        //nt[i]=o[s[i]];
        //if(nt[i]==-1)nt[i]=i;
        //cout<<nt[i]<<" ";
        if(o[s[i]]==-1)o[s[i]]=i;
        ct[s[i]]++;
        /*cout<<i<<":"<<nt[i]<<":"<<s[i]<<endl;
        for(int i=1;i<=m;i++){
            cout<<o[i]<<" ";
        }
        cout<<endl;*/
    }
    //cout<<endl;
    /*for(int i=1;i<=n;i++){
        cout<<nt[i]<<" ";
    }*/
    //cout<<endl;
    for(int i=1;i<=m;i++){
        nt[i]=s[o[i]+1];
        //cout<<ct[i]<<" "<<nt[i]<<endl;
        v[nt[i]].push_back(i);
    }
    //cout<<endl;
    dfs(0);
    for(int i=1;i<=m;i++){
        cout<<vis[i]<<" ";
    }
    return 0;
}
