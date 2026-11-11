#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int f=1,sum=0;
    char c=getchar();
    while(!(c<='9'&&c>='0')){if(c=='-')f=-1;c=getchar();}
    while(c<='9'&&c>='0'){sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
    return f*sum;
}
int a[500005];
struct q{
    int x;
    int p;
}b[500005];
int pos[300005];
int cnt[300005];
bool cmp(q a,q b){
    if(a.x!=b.x)return a.x<b.x;
    return a.p<b.p;
}
int diff[500005];
int sum[500005];
int sum2[500005];
int nex[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    bool flag = true;
    int n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]<a[i-1])flag=false;
        b[i].x=a[i];
        b[i].p=i;
    }
    if(flag){
        a[n+1]=-1;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                cnt[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" ";
        }
        return 0;
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(b[i].x==b[i+1].x){
            nex[b[i].p]=b[i+1].p;
        }else{
            nex[b[i].p]=-1;
        }
    }
    /***
    for(int i=1;i<=n;i++){
        if(nex[i]!=-1){
            diff[i]+=i;
            diff[nex[i]]-=i;
        }
    }
    for(int i=1;i<=n;i++){
        sum2[i]=sum2[i-1]+diff[i];
    }
    for(int i=1;i<=n;i++){
        if(nex[i]!=-1){
            int re =
        }
    }
    for(int i=1;i<=n;i++){
        sum2[i]=sum2[i-1]+diff[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=i-sum2[i];
        cnt[a[i]]+=sum[i];
    }
    ***/
    for(int i=1;i<=n;i++){
        if(nex[i]!=-1){
            int pl = (i-sum2[i]);
            for(int j=i;j<nex[i];j++){
                sum2[j]+=pl;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]+=(i-sum2[i]);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
