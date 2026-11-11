#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
long long q,a,b,c[2000005],t,maxn[2000005][3],cnt,vis[2000005];
void ma(int x,int y){
    if(x<maxn[y][0]){
        maxn[y][2]=maxn[y][1];
        maxn[y][1]=maxn[y][0];
        maxn[y][0]=x;
    }
    else{
        if(x<maxn[y][1]){
            maxn[y][2]=maxn[y][1];
            maxn[y][1]=x;
        }
        else{
            if(x<maxn[y][2]){
                maxn[y][2]=x;
            }
        }
    }
}
void bfs(int st){
    queue<int> q;
    memset(maxn,0x3f,sizeof(maxn));
    memset(vis,0,sizeof(vis));
    q.push(st);
    maxn[st][0]=0;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(int n=h+1;n<=a;n++){
            if(c[n]-c[h]>b) break;
            else{
                if(vis[n]<3){
                    int x=maxn[h][0]+1;
                    int y=maxn[h][1]+1;
                    int z=maxn[h][2]+1;
                    ma(x,n);
                    ma(y,n);
                    ma(z,n);
                    if(vis[n]==0)
                    q.push(n);
                    vis[n]++;
                }
            }
        }
    }
    for(int n=1;n<=a;n++){
        if(maxn[n][0]==maxn[n][1]&&maxn[n][0]!=maxn[n][2]){
            cnt++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>q>>t;
    while(t--){
        cin>>a>>b;
        for(int n=1;n<=a;n++) cin>>c[n];
        cnt=0;
        for(int n=1;n<=a;n++) bfs(n);
        cout<<cnt<<endl;
    }

    return 0;
}
