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
    const int N=5e5+5,M=505;
    const long long INF=1e18;
    int Case,n,m,d,q;
    int w[N];
    long long f[M][M];

    struct stu { int i,t; };
    vector<stu> in[N];

    int main() {
        Case=read(),n=read(),m=read(),d=read(),q=read();
        for(int i=1;i<=m;i++) w[i]=read();
        for(int i=1;i<=n;i++) {
            int k=read();
            for(int j=1;j<=k;j++) {
                int x,t;
                x=read(),t=read();
                in[x].push_back(stu{i,t});
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) f[i][j]=f[j][i]=INF;
        }
        for(int i=1;i<=m;i++) {
            for(int j=0;j<(int)in[i].size();j++) {
                auto x=in[i][j];
                for(int k=j+1;k<(int)in[i].size();k++) {
                    auto y=in[i][k];
                    f[x.i][y.i]=f[y.i][x.i]=min(f[x.i][y.i],1ll*x.t+1ll*y.t);
                }
            }
        }
        for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
        while(q--) {
            int x=read(),y=read();
            long long ans=INF;
            for(auto p1:in[x]) {
                for(auto p2:in[y]) ans=min(ans,f[p1.i][p2.i]+p1.t+p2.t);
            }
            printf("%lld\n",ans+w[x]+w[y]);
        }

        return 0;
    }
}
char END;

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    clock_t begin=clock();
    Cherry::main();
    clock_t end=clock();
    fprintf(stderr,"Time: %.3lf/1.0 s\n",(end-begin)/1000.0);
    fprintf(stderr,"Memory: %.3lf/1024 MB\n",abs(&BEGIN-&END)/1024.0/1024.0);

    return 0;
}
//g++ subway.cpp -o subway -std=c++14 -Wall -O2 "-Wl,--stack=2000000000"
/*
每 30min 决策一次！！！
冷静！！！
最后要把代码放到 CQ- 里面！！！
对拍！！！
freopen！！！

Time: 0.447s
Memory: 25MB

边界情况/无解
long long
INF

二分、贪心、正难则反、分治、定一求一
*/
/*
我干想了 20min 它过来告诉我
地铁是双向任意同行？？？
行行行
O(md^2+n^3+qd^2)
*/