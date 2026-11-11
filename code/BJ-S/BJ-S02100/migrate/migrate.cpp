#include<bits/stdc++.h>
using namespace std;
int c,t;
int vis[2000010];
int cnt=0;
void dfs(int d,int now,int ter,int len,int minlen){
    if(vis[ter]==1){
        if(len==minlen){
            cnt++;
        }else if(len<minlen){
            cnt=1;
            minlen=len;
        }
        return;
    }
    for(int i=1;i<=d;i++){
        if(vis[now+i]==0){
            vis[now+i]=1;
            dfs(d,now+i,ter,len+1,minlen);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cnt=0;
        int x[2000010];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        dfs(d,x[1],x[n],0,100000);
        cout<<cnt<<"\n";
    }

    return 0;
}
