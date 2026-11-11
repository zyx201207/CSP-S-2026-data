#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
    #define IOSIZE 1000000
    char ibuf[IOSIZE]; char *p1=ibuf,*p2=ibuf;
    #define getchar() ((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?EOF:(*p1++))
    inline int read() { // 注意正负性和类型！！！
        int ans=0; char ch='l';
        while(ch<'0'||ch>'9') ch=getchar();
        while(ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-'0',ch=getchar();
        return ans;
    }
}
using namespace FastIO;

char BEGIN;
namespace Cherry {
    const int N=1e6+5,M=4005;
    int Case,T,n,K;

    struct edge {
        int y,nextt;
    }e[2*N];
    int tot;
    int elast[N];
    void add(int x,int y) {
        e[++tot].y=y;
        e[tot].nextt=elast[x];
        elast[x]=tot;
    }

    namespace Q1 {
        int now[N],d[N],mx[N],smx[N],nmx[N],nsmx[N],f[M][M];
        bool app[N];
        void dfs1(int x,int fa,int dep,int lim) {
            now[dep]=x;
            if(dep>lim) app[now[dep-lim]]=1;
            for(int i=elast[x];i;i=e[i].nextt) {
                int y=e[i].y;
                if(y==fa) continue;
                dfs1(y,x,dep+1,lim);
            }
        }
        int dfs2(int x,int fa) {
            int num=0;
            for(int i=elast[x];i;i=e[i].nextt) {
                int y=e[i].y;
                if(y==fa) continue;
                num+=dfs2(y,x);
            }
            num+=app[x],app[x]=0;
            return num;
        }
        void dfs3(int x,int fa,int dep) {
            d[x]=dep,mx[x]=dep,nmx[x]=x,smx[x]=nsmx[x]=0;
            for(int i=elast[x];i;i=e[i].nextt) {
                int y=e[i].y;
                if(y==fa) continue;
                dfs3(y,x,dep+1);
                if(mx[y]>mx[x]) smx[x]=mx[x],nsmx[x]=nmx[x],mx[x]=mx[y],nmx[x]=y;
                else if(mx[y]>smx[x]) smx[x]=mx[y],nsmx[x]=y;
            }
            // cout<<"mx: "<<x<<" "<<mx[x]<<" "<<nmx[x]<<" "<<smx[x]<<" "<<nsmx[x]<<endl;
        }
        bool dfs4(int x,int fa,int lim,int k,int mxdep) {
            // cout<<"dfs4: "<<x<<" "<<fa<<" "<<f[x][fa]<<" "<<k<<" "<<mxdep<<endl;
            if(d[x]>mxdep) return 0;
            if(f[x][fa]<=k) return 1;
            for(int i=elast[x];i;i=e[i].nextt) {
                int y=e[i].y;
                if(y==fa) continue;
                int maxx=(nmx[x]==y?smx[x]:mx[x]); // 除 y 最大深度
                if(maxx-d[x]+1>lim) continue;
                int tmp=mxdep;
                if(maxx-1>lim) tmp=min(tmp,lim-maxx+2*d[x]);
                // cout<<"tmp: "<<x<<" "<<fa<<" "<<tmp<<"   "<<lim<<" "<<maxx<<" "<<d[x]<<"   "<<mx[x]<<" "<<nmx[x]<<" "<<smx[x]<<endl;
                if(dfs4(y,x,lim,k,tmp)) return 1;
            }
            return 0;
        }

        bool check(int lim) {
            // cout<<"check: "<<lim<<endl;
            for(int i=1;i<=n;i++) {
                app[i]=1;
                dfs1(i,0,1,lim);
                f[i][0]=dfs2(i,0);
                // cout<<"f: "<<i<<" "<<0<<" "<<f[i][0]<<endl;
                if(f[i][0]<=K) return 1;
                for(int j=elast[i];j;j=e[j].nextt) {
                    int x=e[j].y;
                    app[i]=1;
                    dfs1(i,x,1,lim);
                    f[i][x]=dfs2(i,x); // i 除开 x 方向的子树内合法的最小数量，钦定 i 必须选
                    // cout<<"f: "<<i<<" "<<x<<" "<<f[i][x]<<endl;
                }
            }
            for(int rt=1;rt<=n;rt++) {
                dfs3(rt,0,1);
                for(int i=elast[rt];i;i=e[i].nextt) {
                    int x=e[i].y;
                    if(f[rt][x]>=K) continue;
                    // cout<<"??? "<<rt<<" "<<x<<" "<<K-f[rt][x]<<endl;
                    if(dfs4(x,rt,lim,K-f[rt][x],1e9)) return 1;
                }
            }
            return 0;
        }
        void solve() {
            int l=0,r=n-1,mid,ans=n;
            while(l<=r) {
                mid=(l+r)/2;
                if(check(mid)) ans=mid,r=mid-1;
                else l=mid+1;
            }
            printf("%d\n",ans);
        }
    }

    int main() {
        Case=read(),T=read();
        while(T--) {
            n=read(),K=read(),tot=0;
            for(int i=1;i<=n;i++) elast[i]=0;
            for(int i=1;i<n;i++) {
                int x,y;
                x=read(),y=read();
                add(x,y),add(y,x);
            }
            if(Case<=10) Q1::solve();
        }

        return 0;
    }
}
char END;

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    clock_t begin=clock();
    Cherry::main();
    clock_t end=clock();
    fprintf(stderr,"Time: %.3lf/3.0 s\n",(end-begin)/1000.0);
    fprintf(stderr,"Memory: %.3lf/1024 MB\n",abs(&BEGIN-&END)/1024.0/1024.0);

    return 0;
}
//g++ hub.cpp -o hub -std=c++14 -Wall -O2 "-Wl,--stack=2000000000"
/*
每 30min 决策一次！！！
冷静！！！
最后要把代码放到 CQ- 里面！！！
对拍！！！
freopen！！！

Time: 0.579s
Memory: 104MB

边界情况/无解
long long
INF

二分、贪心、正难则反、分治、定一求一
*/