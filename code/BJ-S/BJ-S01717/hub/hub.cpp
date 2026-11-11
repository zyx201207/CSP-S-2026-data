#include<bits/stdc++.h>
using namespace std;
int s=0,c,t,n,k,u,v,book[5005];
vector<int> e[5005];
int dfs(int x,int y){
    if(x==y)return s;
    for(int i=0;i<e[x].size();i++){
        int v=e[x][i];
        if(book[v]==0){
            book[v]=1;
            s++;
            dfs(v,y);
            book[v]=0;
        }
    }
    return s;
}
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
cin>>c>>t;
while(t--){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[u].push_back(v);
    }
    if(k==2){
            int ma=1e8;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    int imax=0;
                for(int l=1;l<=n;l++){
                    s=0;int li=dfs(l,i);
                    s=0;int lj=dfs(l,j);
                    cout<<li<<' '<<lj<<endl;
                    imax=max(imax,min(li,lj));
                }
                cout<<imax<<endl;
            ma=min(ma,imax);
            }
        }
    cout<<ma<<endl;
    }
}
return 0;
}
