#include<bits/stdc++.h>
using namespace std;

int c1,n,m,d,q;
int x,y;
int w[500015],flag[500015],c[500015];

vector<int>s_path_id[500015];
vector<pair<int,int>>a[515];//first:subway_id second:cost
queue<int>que;

int main(){
    freopen("subway.in","r",stdin);
    scanf("%d%d%d%d%d",&c1,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[m]);
    for(int i=1;i<=n;i++){
        //printf("stdin i=%d\n",i);
        int z;
        scanf("%d",&z);
        for(int j=1;j<=z;j++){
            scanf("%d%d",&x,&y);
            s_path_id[x].push_back(i);
            a[i].push_back({x,y});
        }
    }
    while(q--){
        memset(c,-1,sizeof(c));
        scanf("%d%d",&x,&y);
        que.push(x);
        flag[x]=1;
        c[x]+=w[x];
        while(!que.empty()){
            int x1=que.front();
            que.pop();
            int num=s_path_id[x1].size();
            //s_path_id[x1].size()x1有几条路 
            //a[s_path_id[x1][i]].size() x1的第i条路经过几站
            //a[s_path_id[x1][i]][j].first x1的第i条路经过的第j站编号
            //s_path_id[x1][i] x1的第i条路编号
            for(int i=0;i<num;i++){
                //printf("a[s_path_id[x1][i]].size()=%ld\n",a[s_path_id[x1][i]].size() );
                for(int j=0;j<a[s_path_id[x1][i]].size();j++){// a[s_path_id[x1][i]]
                    int num2=a[s_path_id[x1][i]][j].first;
                    int num3=c[x1]+a[s_path_id[x1][i]][j].second+a[num2][j].second;
                    printf("num2=%d i=%d j=%d flag[num2]=%d c[num2]=%d OK\n",num2,i,j,flag[num2],c[num2]);
                    if(flag[num2]==0 && (c[num2] > num3 || c[num2]==-1)){
                        printf("OK\n");
                        que.push(num2);//inque
                        c[num2]=num3;    
                        flag[num2]=1;
                    }else if(c[num2] > num3 || c[num2]==-1) c[num2]=num3;
                }
                
            }
        }
        printf("%d\n",c[y]);
    }

    return 0;
}