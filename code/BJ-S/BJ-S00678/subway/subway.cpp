#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

namespace IO{
    struct INID{INID(){ios::sync_with_stdio(false);cin.tie(nullptr);}};
    int gc(){return cin.rdbuf()->sbumpc();}
    void pc(char c){cout.rdbuf()->sputc(c);}
    template<typename T>void rd(T &x){
        x=0;int f=1,c=gc();
        while('0'>c||c>'9'){
            if(c==EOF){cerr<<"IIE";exit(0);}
            if(c=='-'){f*=-1;}
            c=gc();
        }
        while('0'<=c&&c<='9'){
            x=x*10+c-'0';
            c=gc();
        }
        x*=f;
    }
    template<typename T>void wt(T x){
        if(x<0){pc('-');}
        static int stk[40],tp,d;
        tp=0;
        do{
            d=x%10;
            stk[++tp]=(d<0?-d:d)+'0';
            x/=10;
        }while(x);
        while(tp){pc(stk[tp--]);}
    }
}using namespace IO;

#define int long long

constexpr int M=5e5+5;
constexpr int N=5e2+5;
constexpr int inf=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
int w[M];
int k[M];

vector<int>a[N];//第i辆火车，途径哪些节点

map<pair<int,int>,int>transt;//第i个站点到第j个火车换乘时间

vector<int>trn[M];//节点有那些线路

int f[N][N];

void global(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}

namespace tqy{
    void init(){
        rd(c);
        rd(n);
        rd(m);
        rd(d);
        rd(q);
        for(int i=1;i<=m;++i){
            rd(w[i]);
        }
        for(int i=1;i<=n;++i){
            rd(k[i]);
            for(int j=1;j<=k[i];++j){
                int nd,tm;
                rd(nd),rd(tm);
                a[i].emplace_back(nd);
                transt[make_pair(nd,i)]=tm;
                trn[nd].emplace_back(i);
            }
        }
    }   
    void solve(){
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=n;++i){
            f[i][i]=0;
            for(int j=0;j<k[i];++j){
                int nd=a[i][j];
                for(auto t1:trn[nd]){
                    if(t1==i)continue;
                    f[i][t1]=min(f[i][t1],transt[make_pair(nd,i)]+transt[make_pair(nd,t1)]);
                }
            }
        }
        for(int mid=1;mid<=n;++mid){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    f[i][j]=min(f[i][j],f[i][mid]+f[mid][j]);
                }
            }
        }
        for(int i=1;i<=q;++i){
            int x,y;
            rd(x),rd(y);
            int ans=inf;
            for(auto t1:trn[x]){
                for(auto t2:trn[y]){
                    ans=min(ans,w[x]+w[y]+transt[make_pair(x,t1)]+transt[make_pair(y,t2)]+f[t1][t2]);
                }
            }
            wt(ans),pc('\n');
        }
    }
}

signed main(){
    global();
    int T=1;
    while(T--)tqy::init(),tqy::solve();
    return 0;
}

/*
g++ 2.cpp -o 2 -fsanitize=leak,address,undefined -O2

cd常数太大

偶遇神秘stl平尽全力无法卡常数

为什么我单纯循环都T???????????

怀疑是机器性能太差

不是用freopen比在terminal用文件重定向快多了。。。。。。。。。。。。。。。。。。

玄学问题

*/