#include<bits/stdc++.h>
using namespace std;

const int N=2000005;
long long D,A[N],ans;
int Tid,Tcnt,n,toR[N],dp[N][3];

template<typename qwq>inline void cmin(qwq &a,qwq b){(a>b)&&(a=b);}
template<typename qwq>inline void cmax(qwq &a,qwq b){(a<b)&&(a=b);}

template<typename qwq>inline void read(qwq &a){
    a=0;int c=getchar(),f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) a=10*a+c-'0',c=getchar();
    if(f) a=-a;
}

void solve(){
    read(n),read(D),ans=0;
    // if(Tcnt==10) cerr<<n<<' '<<D<<'\n';
    for(int i=1;i<=n;i++) read(A[i]);
    for(int l=1,r=1;l<=n;l++){
        for(;r<=n&&A[r]-A[l]<=D;r++);
        toR[l]=r-1;
    }
    // for(int r=n,l=n;r>=1;r--){
    //     for(;l>=1&&A[r]-A[l]<=D;l--);
    //     toL[r]=l+1;
    // }
    for(int i=n,p,r;i>=1;i--){//dp:m>=3 only
        dp[i][0]=dp[i][1]=dp[i][2]=0;
        if((p=toR[i])==i||(r=toR[p])==p) continue;
        if(i+1==p||toR[p-1]==p){
            dp[i][0]=toR[p]-p+dp[p][0];
            dp[i][1]=dp[p][1];
        }
        else if(i+2==p||toR[p-2]==p){
            dp[i][0]=toR[p]-toR[p-1];
            dp[i][2]=dp[i][1]=toR[p-1]-p;
            if(toR[p-1]==r) dp[i][1]+=dp[p][0],dp[i][2]+=dp[p][0];
            else{
                dp[i][0]+=dp[p][0],dp[i][1]+=dp[p][1];
                if(toR[p-1]==r-1&&r-1!=p) dp[i][1]-=dp[p][2];
            }
        }
        else{
            dp[i][0]=toR[p]-toR[p-1];
            dp[i][2]=dp[i][1]=toR[p-1]-toR[p-2];
            if(toR[p-1]==r){
                if(toR[p-2]==toR[p-1]);
                else dp[i][1]+=dp[p][0],dp[i][2]+=dp[p][0];
            }
            else{
                dp[i][0]+=dp[p][0],dp[i][1]+=dp[p][1];
                if(toR[p-1]==r-1&&r-1!=p) dp[i][1]-=dp[p][2];
            }
        }
    }
    for(int i=1;i<=n;i++) ans+=dp[i][1];
    printf("%lld\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(read(Tid),read(Tcnt);Tcnt--;) solve();
    return 0;
}
/*
O(n)
finish migrate 17:51
code by Wxb2010
*/