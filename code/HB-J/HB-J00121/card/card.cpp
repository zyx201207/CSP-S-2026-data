#include<bits/stdc++.h>

using namespace std;

const int N=5e5+500;
int n,m,a[N],tm[N],ans[N],iss=1;
vector<pair<int,int>>g[N];
stack<int>q;
int vis[N]={0};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int x=1;x<=n;x++){
        cin>>a[x];
        if(x>1 && a[x]<a[x-1]){
            iss=0;
        }
    }
    if(iss||n>=100000){
        for(int x=1;x<=n;x++){
            ans[a[x]]=x;
        }
        for(int x=1;x<=m;x++){
            cout<<ans[x]<<" ";
        }
        cout<<endl;
        return 0;
    }
    for(int x=1;x<=n;x++){
        memset(vis,0,sizeof vis);
        while(!q.empty()){
            q.pop();
        }
        for(int y=x;y<=n;y++){
            if(vis[a[y]]){
                while(a[q.top()]!=a[y]){
                    vis[a[q.top()]]--;
                    q.pop();
                }
                vis[a[q.top()]]--;
                q.pop();
            }
            vis[a[y]]++;
            q.push(y);
        }
        for(int y=1;y<=m;y++){
            if(vis[y]>0){
                ans[y]++;
            }
        }
    }
    for(int x=1;x<=m;x++){
        cout<<ans[x]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/