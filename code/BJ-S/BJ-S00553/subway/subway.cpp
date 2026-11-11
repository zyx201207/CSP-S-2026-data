#include<bits/stdc++.h>
using namespace std;

//n:线路数 m:站数 maxN:每站最多线路
int _,n,m,maxN,qN;
int w[114514];
int xn[50000];//[线路]的站数
int xw[50000][500];//[线路]的[第几站]到站台花费
int xz[50000][500];//[线路]的[第几站]对应的站台


int zxn[50000];//[站台]的线路总数
int zx[50000][500];//[站台][第几个]线路（从0开始）
int zw[50000][500];//[站台]到[第几个]线路花费（从0开始）

struct link{
    int to;//连接的线路
    int w;//花费
};

int xLinkn[50000];
link xLinks[50000][500];//[线路]的[第几个]连接

void reportLinkZt(int x1,int x2,int w){
    for(int i=0;i<xLinkn[x1];i++){
        if(xLinks[x1][i].to==x2){
            xLinks[x1][i].w=min(xLinks[x1][i].w,w);
            //cout<<"优化连接"<<x1<<" "<<x2<<" "<<w<<endl;
        }
    }
    for(int i=0;i<xLinkn[x2];i++){
        if(xLinks[x2][i].to==x1){
            xLinks[x2][i].w=min(xLinks[x2][i].w,w);
            return;
        }
    }
    //cout<<"新连接"<<x1<<" "<<x2<<" "<<w<<endl;
    xLinks[x1][xLinkn[x1]].to=x2;
    xLinks[x1][xLinkn[x1]++].w=w;
    xLinks[x2][xLinkn[x2]].to=x1;
    xLinks[x2][xLinkn[x2]++].w=w;
}

void initX(int x){
    //x:当前线路
    for(int i=1;i<xn[x];i++){
        int z=xz[x][i];//z:当前站台
        //cout<<x<<"站台"<<z<<endl;

        for(int j=0;j<zxn[z];j++){
            int tox=zx[z][j];//tox:目标线路
            if(x!=tox)reportLinkZt(x,tox,xw[x][i]+zw[z][j]);
        }
    }
}

int xnToXnW[50000][500];//从[线路]到[线路]的连接花费

void reportLink(int x1,int x2,int w){
    if(xnToXnW[x1][x2]==0||w<xnToXnW[x1][x2]){
        xnToXnW[x1][x2]=w;
        xnToXnW[x2][x1]=w;
    }
}

bool history[50000];//线路是否访问过了
int tmp[50000][500];

int minW(int a,int b,int wTotal){
    //cout<<"minW("<<a<<", "<<b<<", "<<wTotal<<")"<<endl;
    if(tmp[a][b]>0)return tmp[a][b];
    if(a==b){
        return wTotal;
    }
    int res=0x7FFFFFFF;
    for(int i=0;i<xLinkn[a];i++){
        //if(history[x][i])continue;
        //history[x][i]=1;
        if(history[xLinks[a][i].to]==1)continue;
        history[xLinks[a][i].to]=1;
        int r=minW(xLinks[a][i].to,b,wTotal+xLinks[a][i].w);
        if(res==0||r<res)res=r;
        history[xLinks[a][i].to]=0;
    }
    tmp[a][b]=res;
    tmp[b][a]=res;
    //cout<<"="<<res<<endl;
    return res;
}

int main(){
    fstream fi,fo;
    fi.open("subway.in");fo.open("subway.out");
    fi>>_>>n>>m>>maxN>>qN;
    for(int i=1;i<=m;i++)fi>>w[i];
    for(int i=1;i<=n;i++){
        fi>>xn[i];
        for(int j=1;j<=xn[i];j++){
            fi>>xz[i][j]>>xw[i][j];
            zx[ xz[i][j] ][ zxn[xz[i][j]]   ]=i;
            zw[ xz[i][j] ][ zxn[xz[i][j]]++ ]=xw[i][j];
        }
    }
    for(int i=1;i<=n;i++)initX(i);

    for(int i=0;i<qN;i++){
        int a,b;
        fi>>a>>b;
        int res=0;
        for(int xai=0;xai<zxn[a];xai++){
            for(int xbi=0;xbi<zxn[b];xbi++){
                //cout<<"从"<<zx[a][xai]<<"到"<<zx[b][xbi]<<endl;
                int r=w[a]+w[b]+zw[a][xai]+zw[b][xbi]+minW(zx[a][xai],zx[b][xbi],0);
                if(res==0||r<res)res=r;
            }
        }

        fo<<res<<endl;
    }

    return 0;
}
