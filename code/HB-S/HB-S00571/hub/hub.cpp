#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define il inline
#define gc() getchar()
il ll read(){
    ll x=0,f=1;char ch=gc();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
const int N=1e6+5;
int c,T;
int n,k;
vector<int> G[N];
int fa[N];
int ans;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),T=read();
    while(T--){
        n=read(),k=read();
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(k==n) {
            printf("0\n");
            continue;
        }
        /*while(l<=r){
            int mid=l+r>>1;
            if(solve(mid)) r=mid-1,res=ans;
            else l=mid+1;
        }
        printf("%d\n",res);
        */
       int ans=((n+1)/2-k+3+3)/4;
       printf("%d\n",ans);
    }
    return 0;
}
