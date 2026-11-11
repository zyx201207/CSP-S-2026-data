#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N];
bool vis[N];
int nxt[N];
int ans[M];
int mp[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=n;i>=1;i--){
        nxt[i]=mp[a[i]];
        if(!mp[a[i]])mp[a[i]]=i;
    }
    if(n==m){
        for(int i=1;i<=m;i++)printf("%lld ",mp[i]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<=n){
            if(nxt[j])j=nxt[j];
            else{ans[a[j]]++;j++;}
        }
    }
    for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
    return 0;
}
