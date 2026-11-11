#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define eb emplace_back
using namespace std;

inline ll read(){
    char c=getchar();ll f=1,x=0;
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}

const int N=5e5+10,mod=998244353;
ll n,m,a[N],s[N];
void Apeiria(){
    n=read(),m=read();
    rep(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    rep(i,1,n) s[i]=s[i-1]+a[i];
    int ans=0;
    rep(i,1,n){
        int l=1,r=i;
        while(r>=l){
            int md=l+r>>1;
            if(a[i]*(i-md+1)-(s[i]-s[md-1])>m) l=md+1;
            else r=md-1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    rep(i,1,T) Apeiria();
    return 0;
}