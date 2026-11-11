#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pow power
#define ull unsigned ll
template<typename T>void read(T &x){
    x=0; int f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    } 
    while(isdigit(c)) x=10*x+c-'0',c=getchar();
    x*=f;
}
template<typename T>void write(T x){
    if(x<0) putchar('-'),write(-x);
    else if(x<10) putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=2e6+5;
const ll INF=4e18;
int c,T,n,nxt[N],dp[N][3];//0:mid==r,1:mid+1==r,2:mid+1<r
ll d,a[N],ans;
void solve(){
    read(n);read(d);ans=0;
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&a[j]-a[i]<=d) j++;
        nxt[i]=j-1;
    }
    // for(int i=1;i<=n;i++) cout<<i<<" "<<nxt[i]<<endl;
    // for(int x=1;x<=n;x++){
    //     int l=x+1,mid=x,r=nxt[x],res=0;
    //     cout<<"***"<<x<<endl;
    //     while(l<=mid||mid<r){
    //         cout<<l<<" "<<mid<<" "<<r<<endl;
    //         if(mid>=r){
    //             l=nxt[r-1]+1;
    //             r=mid=nxt[r];
    //         }
    //         else if(mid+1==r){
    //             l=nxt[r-1]+1;
    //             mid=nxt[r-1];
    //             r=nxt[r];
    //         }
    //         else{
    //             l=nxt[r-2]+1;
    //             mid=nxt[r-1];
    //             r=nxt[r];
    //         }
    //         res+=mid-l+1;
    //     }
    //     // ans+=res;
    // }
    for(int i=n;i>=1;i--){
        if(nxt[i-1]+1>nxt[i]) dp[i][0]=nxt[i]-nxt[i-1];
        else dp[i][0]=dp[nxt[i]][0]+nxt[i]-nxt[i-1];
        if(nxt[i-1]>=nxt[i]) dp[i][1]=0;
        else if(nxt[i-1]+1==nxt[i]) dp[i][1]=dp[nxt[i]][1];
        else dp[i][1]=dp[nxt[i]][2];
        if(nxt[i-2]+1>nxt[i-1]&&nxt[i-1]>=nxt[i]) dp[i][2]=nxt[i-1]-nxt[i-2];
        else if(nxt[i-1]>=nxt[i]) dp[i][2]=dp[nxt[i]][0]+nxt[i-1]-nxt[i-2];
        else if(nxt[i-1]+1==nxt[i]) dp[i][2]=dp[nxt[i]][1]+nxt[i-1]-nxt[i-2];
        else dp[i][2]=dp[nxt[i]][2]+nxt[i-1]-nxt[i-2];
    }
    for(int i=1;i<=n;i++){
        if(i>=nxt[i]) ans+=0;
        else if(i+1==nxt[i]) ans+=dp[nxt[i]][1];
        else ans+=dp[nxt[i]][2];
    }
    writeln(ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(c),read(T);
    while(T--) solve();
    return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/