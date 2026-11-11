#include<bits/stdc++.h>
#define OpenFile(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define CloseFile fclose(stdin),fclose(stdout)
#define int long long
#define getchar getchar_unlocked
#define rep(x,y,z) for(int x=(y);x<=(z);++x)
#define per(x,y,z) for(int x=(y);x>=(z);--x)
#define N 2000005
using namespace std;
int get(int ans=0,int x=1){
    char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')x=-1;ch=getchar();}
    while(ch>=48&&ch<=57)ans=(ans<<1)+(ans<<3)+ch-48,ch=getchar();
    return ans*x;
}int c,t,n,d,a[N],pre[N],nxt[N],cp[N],cn[N];
void solve(int ans=0){
    vector<int>g;
    n=get(),d=get(),nxt[0]=1;
    rep(i,1,n)a[i]=get();
    int l=1,r=n;
    rep(i,1,n){
        while(a[i]-a[l]>d)++l;
        pre[i]=l,cp[i]=1;
    }per(i,n,1){
        while(a[r]-a[i]>d)--r;
        nxt[i]=r,cn[i]=1;
    }rep(i,1,n)if(nxt[i-1]==i)g.emplace_back(i);
    l=0,r=(int)g.size()-1;
    rep(i,1,r)if(a[g[i]]-a[g[i-1]]>d)cp[g[i-1]]=g[i-1]-g[l]+1,l=i;
    cp[r]=g[r]-g[l]+1;
    per(i,r-1,0)if(a[g[i+1]]-a[g[i]]>d)cn[g[i+1]]=g[r]-g[i+1]+1,r=i;
    cp[0]=g[r]-g[0]+1;
    rep(i,2,n-2)if(i+1==nxt[pre[i+1]]&&i==pre[nxt[i]])ans+=(cp[pre[i+1]]+pre[i+2]-pre[i+1]-(pre[i+2]==i))*(cn[nxt[i]]+nxt[i]-nxt[i-1]-(nxt[i-1]==i+1));
    printf("%lld\n",ans);
}signed main(){
    OpenFile(migrate);
    c=get(),t=get();
    rep(_,1,t)solve();
    CloseFile;
    return 0;
}
