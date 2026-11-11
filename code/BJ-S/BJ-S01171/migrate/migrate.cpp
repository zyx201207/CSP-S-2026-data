#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=2000010;
typedef long long ll;
int c,T;
ll n,d,x[N],sub[N],vis[N];
struct node{
    int id,step;
};
queue<node>q;
void dengchashulie();
int bfs(int u,int v){
    q.push({u,0});
    ll mn=1e18;
    int mncnt=0;
    while(!q.empty()){
        node k=q.front();
        if(k.id==v){
            if(k.step==mn){
                mncnt++;
            }
            if(k.step<mn){
                mncnt=1;
                mn=k.step;
            }
        }
        q.pop();
        for(int i=k.id+1;i<=n;i++){
            if(x[i]-x[k.id]>d)break;
            q.push({i,k.step+1});

        }
    }
    return mncnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    if(c==11||c==12){
        dengchashulie();
        return 0;
    }
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",x+i);
            sub[i-1]=x[i]-x[i-1];
        }

        bool flag=true;
        for(int i=2;i<n;i++){
            if(sub[i]!=sub[i-1]){
                flag=false;
                break;
            }
        }
        if(flag){
            ll sb=sub[1];
            if(d<2*sb){
                puts("0");
                continue;
            }
            ll ans=n-(d/sb)*2+1;
            if(ans<=0)puts("0");
            else printf("%lld\n",ans);
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(bfs(i,j)==2)ans++;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
void dengchashulie(){
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",x+i);
            sub[i-1]=x[i]-x[i-1];
        }
        ll sb=sub[1];
        if(d<2*sb){
            puts("0");
            continue;
        }
        ll ans=n-(d/sb)*2+1;
        if(ans<=0)puts("0");
        else printf("%lld\n",ans);
    }
}
/*
公差为1时：
d=2，ans=n-3;
1 1 1
d=3，ans=0
1 2 3 4 5
1 1 1 1

公差为2时：
d<4,ans=0
d=4，ans=n-3;
1 3 5 7 9 11 13 15
2 2 2 2 2
d=5时，ans=n-3

2 2 2 2 2 2 2
d=6时，ans=n-5
d=8时，ans=n-7

公差为3：
1 4 7 10 13 16 19 22 25
d=6,7,8，ans=n-3
d=9,10,11，ans=n-5
d=12，ans=n-7












综上：(不对)
2*sub<=d<3*sub时，ans=n-3，否则ans=0


*/
