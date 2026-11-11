#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long d[200005][40];
long long t[200005];
long long v[40];
bool cmp (long long x,long long y){
    return x>y;
}
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        long long ss=a[i];
        for(int j=30;j>=0;j--){
            long long sf=pow(2,j);
            if(sf<=ss){
                d[i][j]=1;
                v[j]++;
                ss=ss-pow(2,j);
            }
            if(ss==0){
                break;
            }
        }
    }
    if(m==n){
        int re=pow(2,32)-1;
        for(int j=1;j<=n;j++){
            re=re&a[j];
        }
        printf("%d",re);
        return 0;
    }
    int mx=0,xi=-1;
    for(int i=30;i>=0;i--){
        if(v[i]>=m){
            xi=i;
            break;
        }
    }
    int in=0,k=0;
    for(int i=1;i<=n;i++){
        if(d[i][xi]==1){
            t[++in]=i;
        }
    }
    for(int i=xi;i>=0;i--){
        int num=0;
        for(int j=1;j<=in;j++){
            if(t[j]!=-1&&d[t[j]][i]==1){
                num++;
            }
        }
        if(num==in-k||num<m){
            continue;
        }else if(num>m){
            for(int j=1;j<=in;j++){
                if(t[j]!=-1&&d[t[j]][i]==0){
                    t[j]=-1;
                    k++;
                }
            }
        }else if(num==m){
            int re=pow(2,32)-1;
            for(int j=1;j<=in;j++){
                if(t[j]!=-1){
                    re=re&a[t[j]];
                }
            }
            if(re==pow(2,32)-1){
                re=0;
            }
            printf("%d",re);
            return 0;
        }
    }
    int re=pow(2,32)-1;
    for(int j=1;j<=in;j++){
        if(t[j]!=-1){
            re=re&a[t[j]];
        }
    }
    if(re==pow(2,32)-1){
        re=0;
    }
    printf("%d",re);
    return 0;
}
