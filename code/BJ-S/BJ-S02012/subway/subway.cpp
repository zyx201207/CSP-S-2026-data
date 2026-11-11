#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,t;
}f[510][25];
int w[500010];
vector<int> tg[500010];
int u[510][510];

int main (){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(u,0x3f,sizeof(u));
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++){
            scanf("%d%d",&f[i][j].a,&f[i][j].t);
            if(tg[f[i][j].a].size()){
//                printf("add\n");
                for(int k=0;k<tg[f[i][j].a].size();k++){
//                    printf("u=%d v=%d \n",tg[f[i][j].a][k],i);
                    if(u[tg[f[i][j].a][k]][i]==0x3f3f3f3f) u[tg[f[i][j].a][k]][i]=0;
                    if(u[i][tg[f[i][j].a][k]]==0x3f3f3f3f) u[i][tg[f[i][j].a][k]]=0;
                    u[tg[f[i][j].a][k]][i]+=f[i][j].t;
                    u[i][tg[f[i][j].a][k]]+=f[i][j].t;
                }
            }
            tg[f[i][j].a].push_back(i);    
        }
    }
    // for(int i=1;i<=m;i++){
    //     printf("i=%d tg[i]=",i);
    //     for(int j=0;j<tg[i].size();j++){
    //         printf("%d ",tg[i][j]);
    //     }
    //     printf(" - ");
    // }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%d ",u[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(u[i][k]&&u[k][j]){
                    u[i][j]=min(u[i][j],u[i][k]+u[k][j]);
                }
            }
        }
    }

    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
//        printf("%d\n",u[x][y]+w[x]+w[y]);
        printf("%d\n",w[x]+w[y]);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
我不会写最短路
*/

/*
你好 现在是17：01 这大概是我初中最后一次碰OI了
感谢我大量的低级错误让我在漫长的调试过程中找回了OI的乐趣
我可能真的不适合OI 这是我的第4年了 而我的J仍然不能1=
其实也在情理之中 我几乎学了一整年的whk
我正在不慌不忙的焦虑很多 不慌不忙 因为我还有1.5h 而无法思考T2
焦虑什么样的成绩才能配的上这一年 焦虑接下来的1.5h怎么办
焦虑下周还有期中考试 焦虑晚上还有课 焦虑我一笔没动的作业
段错误(核心已转储)
我的头好疼啊
我决定去上个厕所
*/

/*
maybe 并查集？
*/