#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int c,n,m,d,q;
int tu[505][505];

int w[10000005];
struct sub{
    int number;
    int station[500005];
    int time[500005];
}subway[505];


void same(int x,int y){
    for(int i=1;i<=subway[x].number;i++){
        for(int j=1;j<=subway[y].number;j++){
            if(subway[x].station[i]==subway[y].station[j]){
                tu[i][j]=min(tu[i][j],subway[x].time[i]+subway[y].time[j]);
                tu[j][i]=tu[i][j];
            }
        }
    }
    return;
}

void intu(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            same(i,j);
        }
    }
    return;
}

int where(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=subway[i].number;j++){
            if(subway[i].station[j]==x){
                return i;
            }
        }
    }
}

int djs(int go,int finish){
    long long ans[n+5];
    for(int i=1;i<=n+5;i++){
        ans[i]=0x3f3f3f3f;
    }
    bool vis[n+5]={false};
    queue<int> qq;
    qq.push(go);
    while(!qq.empty()){
        int head=qq.front();
        qq.pop();
        for(int i=1;i<=n;i++){
            if(tu[head][i]!=0 && vis[i]==false){
                ans[i]=min(ans[i],ans[head]+tu[head][i]);
                vis[i]=true;
                qq.push(i);
            }
        }
    }
    return ans[finish];
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&subway[i].number);
        for(int j=1;j<=subway[i].number;j++){
            scanf("%d%d",&subway[i].station[j],&subway[i].time[j]);
        }
    }

    if(c==1||c==2||c==3){
        for(int i=1;i<=q;i++){
            int go,finish;
            scanf("%d%d",&go,&finish);
            long long ans=w[go]+w[finish];
            go=where(go);
            finish=where(finish);
            if(go==finish){
                cout<<ans;
            }else{
                intu();
                cout<<ans+tu[go][finish];
            }
        }
        return 0;
    }

    intu();

    for(int i=1;i<=q;i++){
        int go,finish;
        scanf("%d%d",&go,&finish);
        long long ans=w[go]+w[finish];
        //cout<<ans<<endl;//mmmmmmmmmmmmmmmmmmmmmmmmm
        ans+=djs(where(go),where(finish));
       // cout<<where(go)<<" "<<where(finish)<<endl;//kkkkkkkkkkkkkkkkkkkkk
        printf("%lld\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
