#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> a[N];
int c,t,s,s2,dep[N],ma;
int n,k;
void dfs(int x,int fath){
    dep[x]=dep[fath]+1;
    if(dep[x]>ma){
        ma=dep[x];
        s2=x;
    }
    for(int i=0;i<a[x].size();i++){
        int y=a[x][i];
        if(y!=fath){
            dfs(y,x);
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if(k==n){
            cout<<0<<"\n";
            continue;
        }else if(k==n-1||k==n-2){
            cout<<1<<"\n";
            continue;
        }
        ma=0;
        dfs(1,0);
        s=s2;
        ma=0;
        dfs(s,0);
        if(k==2){

        }
    }
    return 0;
}

