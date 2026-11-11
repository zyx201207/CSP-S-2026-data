#include <bits/stdc++.h>
using namespace std;
/*struct Node{
    long long s,e;
    char c;
};
Node ins[200005];*/
long long dp[1005][1005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    /*long long noww=1,all=0;
    long long n;scanf("%lld",&n);
    for(long long i=1;i<=n;++i){
        long long a;char c;
        scanf("%lld %c",&a,&c);
        ins[i].s=noww;
        noww+=a;ins[i].e=noww;
        ++noww;all+=a;
    }
    long long lpos=1,rpos=n;
    long long cnt=0;
    for(long long i=1,j=all;i<j;++i,--j){
        if(i>ins[lpos].e) ++lpos;
        if(j<ins[rpos].s) --rpos;
        if(ins[lpos].c!=ins[rpos].c) ++cnt;
    }
    printf("%lld",cnt);*/
    string s="";
    long long n;scanf("%lld",&n);
    for(long long i=1;i<=n;++i){
        long long a;char c;
        scanf("%lld %c",&a,&c);
        for(long long j=1;j<=a;++j) s+=c;
    }
    memset(dp,0x3f,sizeof(dp));
    long long num=s.size();
    for(long long i=0;i<num;++i) dp[i][i]=0;
    for(long long i=0;i<num-1;++i)
        dp[i][i+1]=(long long)!(s[i]==s[i+1]);
    for(long long L=2;L<=num;++L){
        for(long long i=0;i<num;++i){
            long long e=i+L;
            if(e>=num) continue;
            if(s[i]==s[e]) dp[i][e]=min(dp[i][e],dp[i+1][e-1]);
            else dp[i][e]=min(dp[i][e],min(dp[i+1][e],dp[i][e-1])+1);
        }
    }
    printf("%lld",dp[0][num-1]);
    return 0;
}
