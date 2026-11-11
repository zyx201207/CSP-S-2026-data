#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define x first
#define y second
inline ll read(){
    ll d=0,f=0;char ch=getchar();
    while (!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) d=d*10+ch-'0',ch=getchar();
    return f?-d:d;
}
const int N=2000005,M=500050;
const  ll inf=1e18;

int n,nxt[N];
ll d,x[N],ans;
pii f[N];
inline pii operator+ (pii a,pii b){
    if (a.x<b.x) return a;
    if (a.x>b.x) return b;
    return {a.x,a.y+b.y};
}
inline void calc(int s){
    // for (int i=s;i<=n;i++) f[i]={1e9,0};
    f[s]={0,1};
    int R=s;
    for (int i=s;i<=R;i++)if (f[i].y){
        f[i].x++;R=max(nxt[i],R);
        if (i<nxt[i]) f[nxt[i]]=f[nxt[i]]+f[i];
        if (i<nxt[i]-1) f[nxt[i]-1]=f[nxt[i]-1]+f[i];
        if (i<nxt[i]-2) f[nxt[i]-2]=f[nxt[i]-2]+f[i];
        if (f[i].y==2) ans++;//,printf("s:%d %d %d %d\n",s,i,f[i].x,f[i].y);
    }
    for (int i=s;i<=R;i++) f[i]={1e9,0};
}

inline void solve(){
    n=read(),d=read(),ans=0;
    for (int i=1;i<=n;i++) x[i]=read(),f[i]={1e9,0};
    for (int i=1,j=1;i<=n;i++){
        while (j<=n&&labs(x[i]-x[j])<=d) j++;
        nxt[i]=j-1;
    }
    for (int i=1;i<=n;i++) calc(i);
    printf("%lld\n",ans);
}

inline void solveA(){
    n=read(),d=read(),ans=0;
    for (int i=1;i<=n;i++) x[i]=read(),f[i]={1e9,0};
    for (int i=1,j=1;i<=n;i++){
        while (j<=n&&labs(x[i]-x[j])<=d) j++;
        nxt[i]=j-1;
    }
    int D=nxt[1]-1;
    if (D==0||D==1) puts("0");
    else printf("%d\n",max(0,n+1-D*2));
}

int lst[N],cnt[N];

inline void solveB(){
    n=read(),d=read(),ans=0;
    for (int i=1;i<=n;i++) x[i]=read(),f[i]={1e9,0};
    for (int i=1,j=1;i<=n;i++){
        while (j<=n&&labs(x[i]-x[j])<=d) j++;
        nxt[i]=j-1;
    }
    for (int i=1,j=1;i<=n;i++){
        while (j<=i&&nxt[j]<i) j++;
        lst[i]=j;
        // printf("lst[%d]=%d\n",i,lst[i]);
    }
    for (int i=1;i<=n;i++) if (lst[i]<i-1) cnt[lst[i]]++;
    for (int i=1;i<=n;i++){
        int j=nxt[i]-1;
        if (j>i) ans+=cnt[j];
    }
    printf("%lld\n",ans);
}

inline void solveC(){
    n=read(),d=read(),ans=0;
    for (int i=1;i<=n;i++) x[i]=read(),f[i]={1e9,0};
    for (int i=1,j=1;i<=n;i++){
        while (j<=n&&labs(x[i]-x[j])<=d) j++;
        nxt[i]=j-1;
    }
    for (int i=1,j=1;i<=n;i++){
        while (j<=i&&nxt[j]<i) j++;
        lst[i]=j;
    }
    for (int i=1;i<=n;i++) if (lst[i]<i-1) cnt[lst[i]]++;
    for (int i=1;i<=n;i++){
        int j=i;
        while (j<=n){
            int k=nxt[j];
            if (k-1>j) ans+=cnt[k-1];
            if (max(i,lst[k])!=j) break;
            if (j<nxt[j]) j=nxt[j];
            else break;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // auto st=clock();
    int c=read(),T=read();
    while (T--) {
        if (c==11||c==12) solveA();
        else if (c==13||c==14) solveB();
        else if (c>=15&&c<=18) solveC();
        else solve();
    }
    // cerr<<"cost:"<<1000*(clock()-st)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}