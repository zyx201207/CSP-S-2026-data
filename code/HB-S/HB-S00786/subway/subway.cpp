//It's yesterday once more. No biggest samples
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
template<typename tp> inline void cmin(tp &a,tp b){(b<a)&&(a=b);}
template<typename tp> inline void cmax(tp &a,tp b){(b>a)&&(a=b);}
template<typename tp> inline void read(tp &x){
    x=0;tp f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^48);ch=getchar();}
    x*=f;
}
template<typename tp> inline void write(tp x,char ed=' '){
    static char stk[40];
    int top=0;
    if(x<0) putchar('-'),x=-x;
    do stk[++top]=x%10+48,x=x/10; while(x);
    while(top) putchar(stk[top--]);
    putchar(ed);
}
const int N=520;
const int M=5e5+10;
int n,m,d,q;
ll G[N][N],wss[M];
using pil=pair<int,ll>;
vector<pil> lines[M];
void mian(){
    read(n),read(m),read(d),read(q);
    memset(G,0x3f,sizeof G);
    for(int i=1;i<=n;i++){
        G[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        read(wss[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        read(k);
        for(int j=1;j<=k;j++){
            int a,t;
            read(a);
            read(t);
            lines[a].emplace_back(i,t);
        }
    }
    for(int x=1;x<=m;x++){
        for(int i=0;i<lines[x].size();i++){
            for(int j=0;j<lines[x].size();j++){
                cmin(G[lines[x][i].first][lines[x][j].first],lines[x][i].second+lines[x][j].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cmin(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    for(int _=1;_<=q;_++){
        int x,y;
        read(x);
        read(y);
        ll dis=LLONG_MAX;
        for(auto i:lines[x]){
            for(auto j:lines[y]){
                cmin(dis,G[i.first][j.first]+i.second+j.second);
            }
        }
        dis+=wss[x]+wss[y];
        write(dis,'\n');
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int _c;
    read(_c);
    mian();
    return 0;
}