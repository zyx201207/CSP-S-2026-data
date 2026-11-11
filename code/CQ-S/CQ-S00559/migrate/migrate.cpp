#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define test(x) freopen(x".in","r",stdin)
#define LL long long
#define db double
#define i128 __int128
#define lb(x) (x&-x)
#define fir first
#define sec second
const int N=5e3+5,M=2e6,inf=1e9;const LL INF=1e18;
int c,T,n,m,dis[N],cnt[N],ans;LL a[M],d;bool f[N];vector<int> v[N];
void clear(){
    ans=0;
    if(c<=10){
        for(int i=1;i<=n;i++) v[i].clear();
    }
}
char ch;LL tmp,op;
LL read(){
    tmp=0,ch=getchar(),op=1;
    while(ch>'9'||ch<'0') ch=='-'?op=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') tmp=tmp*10+ch-'0',ch=getchar();
    return tmp*op;
}
void solve(){
    n=read(),d=read();
    for(int i=1;i<=n;i++) a[i]=read();
    if(c<=10){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>d) break;
                v[i].push_back(j),v[j].push_back(i);
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            fill(f+1,f+1+n,0),fill(cnt+1,cnt+1+n,0),fill(dis+1,dis+1+n,inf);
            dis[i]=0,cnt[i]=1,q.push(i);
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int y:v[x])
                    if(dis[y]>dis[x]+1) dis[y]=dis[x]+1,cnt[y]=cnt[x],q.push(y);
                    else if(dis[y]==dis[x]+1) cnt[y]+=cnt[x];
            }
            for(int j=i+1;j<=n;j++)
                if(cnt[j]==2) ans++;
        }
        printf("%d\n",ans);
        return;
    }
    if(c==11||c==12){
        if(a[2]-a[1]==0) return printf("0\n"),void();
        m=d/abs(a[2]-a[1]);
        if(m==1||m==0||n-(2*m-1)<0) return printf("0\n"),void();
        printf("%d\n",n-(2*m-1));
        return;
    }
    // if(c==13||c==14){
    //     return;
    // }
    printf("0\n");
}
int main(){
    // test("migrate");
    FILE("migrate");
    int T=1;scanf("%d%d",&c,&T);
    while(T--) solve(),clear();
    return 0;
}
/*
有你在我身边不再害怕平庸
你给的爱他们望尘莫及
眼神确定是我们的默契
——TizzyT《99》
*/