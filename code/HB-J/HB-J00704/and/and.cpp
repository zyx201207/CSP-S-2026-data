#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a1[2001];
bool cmp(long long a,long long b){
    return a>b;
}
long long maxn,k=0;
void read(){
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a1[i]);
    }
}
bool vf[2000];
void dfs(long long x,long long ans,long long be){
    k++;
    if(k>8000000){
        return;
    }
    if(x>=m){
        maxn=max(ans,maxn);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vf[i]==0&&i>be){
            vf[i]=1;
            dfs(x+1,ans&a1[i],i);
            vf[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    read();
    sort(a1+1,a1+1+n,cmp);
    if(n>200){
        long long an=a1[1];
        for(int i=2;i<=m;i++){
            an&=a1[i];
        }
        printf("%lld",an);
        return 0;
    }
    dfs(1,a1[1],1);
    printf("%lld",maxn);
    return 0;
}
