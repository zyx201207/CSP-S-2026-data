#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
    #define IOSIZE 1000000
    char ibuf[IOSIZE]; char *p1=ibuf,*p2=ibuf;
    #define getchar() ((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?EOF:(*p1++))
    inline long long read() { // 注意正负性和类型！！！
        long long ans=0,f=1; char ch='l';
        while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
        if(ch=='-') f=-1,ch=getchar();
        while(ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-'0',ch=getchar();
        return ans*f;
    }
}
using namespace FastIO;

char BEGIN;
namespace Cherry {
    const int N=2e6+5;
    int Case,T,n;
    long long D;
    int L[N],R[N];
    long long a[N];

    namespace Q1 {
        bool vis[N][2];
        long long f[N][2];
        long long dfs(int x,int pre,int ti,bool flag) {
            if(x==R[x]) return 0;
            if(ti>1&&vis[x][flag]) return f[x][flag];
            int fl=flag;
            long long res=0;
            if(ti>1) vis[x][flag]=1,f[x][flag]=0;
            if(pre<x-1&&!flag) {
                if(R[x-2]==R[x]) return 0;
                if(ti>1&&L[x-1]<pre) {
                    if(R[x-1]==R[x]) return 0;
                }
                else res+=R[x-1]-R[x-2];
                fl|=(R[x-1]==R[x]);
            }
            else if(flag) {
                if(R[x-1]==R[x]) return 0;
                res+=R[x]-R[x-1];
            }
            res+=dfs(R[x],x,ti+1,fl);
            if(ti>1) f[x][flag]=res;
            // cout<<"f: "<<x<<" "<<flag<<" "<<f[x][flag]<<"  "<<R[x]<<" "<<fl<<endl;
            return res;
        }
        void solve() {
            long long ans=0;
            for(int i=1;i<=n;i++) vis[i][0]=vis[i][1]=0,f[i][0]=f[i][1]=0;
            for(int i=n;i>=1;i--) {
                int x=R[i],pre=i;
                bool flag=0; // 到当前位置前都只有一条路径
                ans+=dfs(x,pre,1,flag);
                // while(x!=R[x]) {
                //     if(pre<x-1&&!flag) {
                //         if(R[x-2]==R[x]) break;
                //         if(pre>i&&L[x-1]<pre) {
                //             if(R[x-1]==R[x]) break;
                //         }
                //         else ans+=R[x-1]-R[x-2];
                //         flag|=(R[x-1]==R[x]);
                //     }
                //     else if(flag) {
                //         if(R[x-1]==R[x]) break;
                //         ans+=R[x]-R[x-1];
                //     }
                //     cout<<"?? "<<x<<" "<<pre<<" "<<ans<<endl;
                //     pre=x,x=R[x];
                // }
                // cout<<"ans: "<<i<<" "<<ans<<endl;
            }
            printf("%lld\n",ans);
        }
    }

    int main() {
        Case=read(),T=read();
        while(T--) {
            n=read(),D=read();
            for(int i=1;i<=n;i++) a[i]=read();
            for(int i=1;i<=n;i++) {
                L[i]=lower_bound(a+1,a+1+n,a[i]-D)-a;
                R[i]=upper_bound(a+1,a+1+n,a[i]+D)-a-1;
                // cout<<"i: "<<i<<" "<<L[i]<<" "<<R[i]<<endl;
            }
            Q1::solve();
        }

        return 0;
    }
}
char END;

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    clock_t begin=clock();
    Cherry::main();
    clock_t end=clock();
    fprintf(stderr,"Time: %.3lf/1.0 s\n",(end-begin)/1000.0);
    fprintf(stderr,"Memory: %.3lf/1024 MB\n",abs(&BEGIN-&END)/1024.0/1024.0);

    return 0;
}
//g++ migrate.cpp -o migrate -std=c++14 -Wall -O2 "-Wl,--stack=2000000000"
/*
每 30min 决策一次！！！
冷静！！！
最后要把代码放到 CQ- 里面！！！
对拍！！！
freopen！！！

Time: 
Memory: 

边界情况/无解
long long
INF

二分、贪心、正难则反、分治、定一求一
*/
/*
0 1
6 3
0 1 2 3 4 7
Out: 0
*/
/*
0 6
10 31746031746031745
-1000000000000000000 -777777777777777785 -555555555555555570 -333333333333333355 -111111111111111140 111111111111111075 333333333333333290 555555555555555505 777777777777777720 999999999999999935
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987

Out: 0 0 7 5 5 0
*/