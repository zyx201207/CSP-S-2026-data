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
    const int N=5e5+5;
    int n;
    long long m;
    long long a[N],sum[N];
    int main() {
        n=read(),m=read();
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        int ans=0;
        for(int i=1;i<=n;i++) {
            int l=1,r=i,mid,p=i;
            while(l<=r) {
                mid=(l+r)/2;
                if(1ll*(i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) p=mid,r=mid-1;
                else l=mid+1;
            }
            ans=max(ans,i-p+1);
        }
        printf("%d\n",ans);

        return 0;
    }
}
char END;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    clock_t begin=clock();
    Cherry::main();
    clock_t end=clock();
    fprintf(stderr,"Time: %.3lf/1.0 s\n",(end-begin)/1000.0);
    fprintf(stderr,"Memory: %.3lf/1024 MB\n",abs(&BEGIN-&END)/1024.0/1024.0);

    return 0;
}
//g++ crystal.cpp -o crystal -std=c++14 -Wall -O2 "-Wl,--stack=2000000000"
/*
每 30min 决策一次！！！
冷静！！！
最后要把代码放到 CQ- 里面！！！
对拍！！！
freopen！！！

Time: 0.038s
Memory: 7.630MB

边界情况/无解
long long
INF

二分、贪心、正难则反、分治、定一求一
*/