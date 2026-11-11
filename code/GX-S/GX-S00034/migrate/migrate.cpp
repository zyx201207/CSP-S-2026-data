#include<bits/stdc++.h>
using namespace std;

int T;
int n,as;
long long d;
int dis[5010];
int cnt[5010];
long long a[2000010];
int Begin[5010],To[25000010],Next[25000010],etot;
void add(int x,int y){
    To[++etot] = y;
    Next[etot] = Begin[x];
    Begin[x] = etot;
}
struct node{
    int ds,id;
    node(int inx=0,int iny=0){id=inx,ds=iny;}
};
bool operator<(node x,node y){
    return x.ds>y.ds;
}
priority_queue<node> q;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d",&T);
    scanf("%d",&T);

    while(T--){
        etot = 0;as = 0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            Begin[i] = 0;
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    add(i,j);
                }
            }
        }

        node now;
        for(int i=1;i<=n;i++){
            memset(dis,0x3f,sizeof(dis));
            memset(cnt,0,sizeof(cnt));
            q.push(node(i,0));
            dis[i] = 0;
            while(!q.empty()){
                now = q.top();q.pop();
                if(now.ds > dis[now.id]){
                    continue;
                }
                for(int j=Begin[now.id];j!=0;j=Next[j]){
                    if(dis[now.id]+1 < dis[To[j]]){
                        dis[To[j]] = dis[now.id]+1;
                        cnt[To[j]] = 1;
                        q.push(node(To[j],dis[To[j]]));
                    }
                    else if(dis[now.id]+1 == dis[To[j]]){
                        cnt[To[j]]++;
                    }
                }
            }
            for(int j=1;j<=n;j++){
                if(cnt[j] == 2){
                    as++;
                }
            }
        }

        printf("%d\n",as);
    }

    return 0;
}
