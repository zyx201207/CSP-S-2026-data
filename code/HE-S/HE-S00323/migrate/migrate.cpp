#include<bits/stdc++.h>
using namespace std;
struct node{
    int wz,step;
};
int c,t,n,d,mn,ans,ret;
const int N=2e5+10;
int x[N];
queue<node>q;
int bfs(int sx,int tx){
    node temp;
    temp.wz=x[sx];
    temp.step=0;
    q.push(temp);
    while(!q.empty()){
        node f=q.front();
        q.pop();
        for(int i=f.wz;i<=f.wz+d;i++){
            for(int j=1;j<=n;j++){
                if(x[j]==i){
                    node t;
                    t.wz=i;
                    t.step=f.step+1;
                    q.push(t);
                    if(i==x[tx]){
                        return t.step;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
void dfs(int sx,int tx,int st,int cnt){
    if(sx>tx){
        return;
    }
    if(sx==tx){
        if(st==cnt){
            ans++;
        }
        return;
    }
    for(int i=sx+1;i<=sx+d;i++){
        for(int j=1;j<=n;j++){
            if(x[j]==i){
                dfs(x[j],tx,st,cnt+1);
            }
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ret=0;
        memset(x,0,sizeof(x));
        while(!q.empty()){
            q.pop();
        }
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mn=bfs(i,j);
                dfs(x[i],x[j],mn,0);
                if(ans==2){
                    ret++;
                }
                while(!q.empty()){
                    q.pop();
                }
                ans=0;
            }
        }
        cout<<ret<<endl;
    }
}
