#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
int read(){
    int x=0,f=1;char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f=-1;ch = getchar();}
    while(ch >='0' && ch <= '9'){x=x*10+ch-'0';ch = getchar();}
    return x*f;
}
const int M = 2e4+10;
int w[N],t[N][M],a[N][M],k[N],nt[N][M];

ll mn=LLONG_MAX,id = 0;
struct Node{
	int v,c;
};
vector<Node> edge[N];
int vis[N];
vector<int> num[N];
int n,m,d,q;

void dfs(int u,int t,ll cnt,int c){

    if(u == t){
        if(mn >= cnt){
            mn = cnt;
            id = c;
        }
        return;
    }
    for(int i = 0;i < edge[u].size();i ++){

        int v = edge[u][i].v;
        int vc = edge[u][i].c;
        if(!vis[v]){
            vis[v] = 1;
            if(c != vc){

                dfs(v,t,cnt+nt[c][u]+nt[vc][u],vc);
            }else{
                dfs(v,t,cnt,vc);
            }
            vis[v] = 0;
        }
    }
}

int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    int c=read();
    n = read(),m=read(),d=read(),q=read();
    for(int i = 1;i <= m;i ++) w[i]=read();
    for(int i = 1;i <= n;i ++){
        k[i] = read();
        for(int j = 1;j <= k[i];j ++){
            a[i][j] = read();
            num[a[i][j]].push_back(i);
            t[i][j] = read();
        }
    }

    for(int i = 1;i <= n;i ++){
        for(int j = 2;j <= k[i];j ++){
            edge[a[i][j]].push_back({a[i][j-1],i});
            edge[a[i][j-1]].push_back({a[i][j],i});
        }
    }

    for(int i = 1;i<= n;i ++){
        for(int j = 1;j <= k[i];j++){
            nt[i][a[i][j]] = t[i][j];
        }
    }
    for(int i = 1;i <= q;i ++){
        int s = read(),t = read();
        mn=LLONG_MAX;
        ll lol =LLONG_MAX,od = 0;

        for(int j = 0;j < num[s].size();j ++){
            dfs(s,t,0,num[s][j]);
            if(lol > mn){
                lol = mn;
                od = num[s][j];
            }
        }
        printf("%lld\n",nt[od][s]+w[s]+mn+w[t]+nt[id][t]);
    }

    return 0;
}
