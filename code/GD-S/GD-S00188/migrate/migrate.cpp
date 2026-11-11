#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
    char bufin[1<<20],*fs,*ft;
    char getc(){
        return (fs==ft&&(ft=(fs=bufin)+fread(bufin,1,1<<20,stdin),fs==ft))?EOF:*fs++;
    }
    template<class T>
    void read(T& x){
        x=0;
        int f=1;
        char ch=getc();
        while(ch<'0'||ch>'9'){
            if(ch=='-') f=-1;
            ch=getc();
        }
        while(ch>='0'&&ch<='9'){
            x=10*x+(ch-'0');
            ch=getc();
        }
        if(f==-1) x=-x;
    }
}
using FastIO::read;
const int N=2000005;
int n;
ll d;
ll p[N];
int nxt[N];
int dp[N];
int f(int r,int x);
int f(int r,int x,int y);
int f(int r,int x,int y,int z);
int w(int x,int y,int z){
    return nxt[x]>=y?z:0;
}
bool vis1[N][2];
int rec1[N][2];
int f(int r,int x){
    if(nxt[r]==r||x>2) return 0;
    if(vis1[r][x-1]) return rec1[r][x-1];
    int &res=rec1[r][x-1];
    vis1[r][x-1]=1;
    if(nxt[r]==r+1) return res=((x==2)+f(r+1,x));
    if(nxt[r]==r+1) return res=((x==2?2:0)+f(r+2,x,x));
    return res=((x==2?nxt[r]-r:0)+f(nxt[r],x,x,x));
}
bool vis2[N][2][2];
int rec2[N][2][2];
int f(int r,int x,int y){
    if(nxt[r]==r||y>2) return 0;
    x=min(x,2);
    if(vis2[r][x-1][y-1]) return rec2[r][x-1][y-1];
    vis2[r][x-1][y-1]=1;
    int &res=rec2[r][x-1][y-1];
    res=0;
    if(x+y==2) res+=nxt[r-1]-r;
    if(y==2) res+=nxt[r]-nxt[r-1];
    if(nxt[r]==r+1) return res+=f(r+1,w(r-1,r+1,x)+y);
    if(nxt[r]==r+2) return res+=f(r+2,w(r-1,r+1,x)+y,w(r-1,r+2,x)+y);
    return res+=f(nxt[r],w(r-1,nxt[r]-2,x)+y,w(r-1,nxt[r]-1,x)+y,w(r-1,nxt[r],x)+y);
}
bool vis3[N][2][2];
int rec3[N][2][2];
int f(int r,int x,int y,int z){
    if(nxt[r]==r||z>2) return 0;
    y=min(y,2);
    x=min(x,1);
    if(vis3[r][y-1][z-1]) return rec3[r][y-1][z-1];
    vis3[r][y-1][z-1]=1;
    int &res=rec3[r][y-1][z-1];
    res=0;
    if(y+z==2) res+=nxt[r-1]-nxt[r-2];
    if(z==2) res+=nxt[r]-nxt[r-1];
    if(nxt[r]==r+1) return res+=f(r+1,w(r-2,r+1,x)+w(r-1,r+1,y)+z);
    if(nxt[r]==r+2) return res+=f(r+2,w(r-2,r+1,x)+w(r-1,r+1,y)+z,w(r-2,r+2,x)+w(r-1,r+2,y)+z);
    return res+=f(nxt[r],w(r-2,nxt[r]-2,x)+w(r-1,nxt[r]-2,y)+z,w(r-2,nxt[r]-1,x)+w(r-1,nxt[r]-1,y)+z,w(r-2,nxt[r],x)+w(r-1,nxt[r],y)+z);
}
void solve(){
    read(n),read(d);
    for(int i=1;i<=n;i++)
        read(p[i]);
    for(int i=1,j=1;i<=n;i++){
        j=max(i,j);
        while(j<n&&p[j+1]<=p[i]+d) ++j;
        nxt[i]=j;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            vis1[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                vis2[i][j][k]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                vis3[i][j][k]=0;
    for(int i=n;i>=1;i--)
        dp[i]=f(i,1);
    ll res=0;
    for(int i=1;i<=n;i++)
        res+=dp[i];
    printf("%lld\n",res);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(;t;--t) solve();
}