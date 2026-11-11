#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans;
bool vis[N];
int read(){
    int su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(),m=read(),ans=0;
    for(int i=1;i<=n;i++)a[i]=read(),vis[i]=1;
    for(int x=29;x>=0;x--){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(vis[i]&&((a[i]>>x)&1))cnt++;
        if(cnt<m)continue;
        ans|=(1<<x);
        for(int i=1;i<=n;i++)
            if(vis[i]&&(!((a[i]>>x)&1)))vis[i]=0;
    }
    cout<<ans<<"\n";
    return 0;
}
