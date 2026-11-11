#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;//m站 n条线路
struct Node{
    int w;
    int xl[25]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
}tr[100010];
int luxian[510][100010];

//int w[100010];//地铁口到站厅的时间
//int xl[100010][25];//每个地铁站站厅走到第 i 条线路的站台

void dfs(int st,int en){
    for(int i=1;i<=d;i++){
        if(tr[st].xl[i]!=-1){

        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>tr[i].w;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;//k 条线路
        for(int j=1;j<=k;j++){
            int sta,stim,cnt=0;
            cin>>sta>>stim;//
            luxian[j][cnt]=sta;
            cnt++;
            tr[sta].xl[k]=stim;
        }
    }
    while(q--){
        int st,en;
        cin>>st>>en;
        dfs(st,en);
    }
    return 0;
}
