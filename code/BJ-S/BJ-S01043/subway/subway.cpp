#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXM 500005
#define MAXN 505
#define int long long
int c,n,m,d,q,w[MAXM],k,a,t,x,y,edg[MAXN][MAXN],arr[MAXN],tme[MAXN],tb[MAXN][MAXN],ans;
vector<pair<int,int>> have[MAXM];
int read(){
    int c=getchar(),x=0,tm=1;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    if(c=='-'){
        tm=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x*=10;
        x+=c-'0';
        c=getchar();
    }
    return x*tm;
}
int buff[200],tp;
void write(int x){
    if(x==0){
        putchar('0');
        return;
    }
    if(x<0){
        putchar('-');
        x=-x;
    }
    tp=0;
    while(x){
        buff[++tp]=x%10;
        x/=10;
    }
    do{
        putchar(buff[tp]+'0');
    }while(--tp);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            edg[i][j]=tb[i][j]=LLONG_MAX/5;
    for(int i=1;i<=n;i++)
        edg[i][i]=tb[i][i]=0;
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        k=read();
        for(int j=1;j<=k;j++){
            a=read();
            t=read();
            //arr[j]=a,tme[j]=t;
            have[a].push_back({i,t});
        }
        /*for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                if(edg[arr[j]][arr[l]]>tme[j]+tme[l]){
                    edg[arr[j]][arr[l]]=edg[arr[l]][arr[j]]=tme[j]+tme[l];
                }
            }
        }*/
    }
    for(int i=1;i<=m;i++){
        for(int j=0,ed=have[i].size();j<ed;j++){
            for(int l=j;l<ed;l++){
                int u=have[i][j].first,v=have[i][l].first,tme=have[i][j].second+have[i][l].second;
                if(edg[u][v]>tme){
                    edg[u][v]=edg[v][u]=tme;
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edg[i][j]==LLONG_MAX/5) cout<<"INF"<<' ';
            else cout<<edg[i][j]<<' ';
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            tb[i][j]=edg[i][j];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                tb[i][j]=min(tb[i][j],tb[i][k]+tb[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tb[i][j]==LLONG_MAX/5) cout<<"INF"<<' ';
            else cout<<tb[i][j]<<' ';
        }
        cout<<endl;
    }*/
    for(int i=1;i<=q;i++){
        x=read();
        y=read();
        ans=LLONG_MAX;
        for(int j=0,ed=have[x].size();j<ed;j++){
            for(int l=0,ed2=have[y].size();l<ed2;l++){
                int tmp=have[x][j].second+have[y][l].second+tb[have[x][j].first][have[y][l].first];
                if(tmp<ans) ans=tmp;
            }
        }
        write(ans+w[x]+w[y]);
        putchar('\n');
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
