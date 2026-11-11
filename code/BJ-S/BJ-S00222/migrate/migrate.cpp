#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
__int128 d,a[2000001];
struct node{
    int w,cnt;
}dis[5001][5001];
__int128 read(){
    __int128 x=0,f=1;char c=getchar_unlocked();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar_unlocked();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar_unlocked();}
    return x*f;
}
__int128 abss(__int128 x){
    if(x>=0)return x;
    else return -x;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;while(t--){
        ans=0;
        cin>>n;d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            if(i!=j&&abss(a[i]-a[j])<=d)dis[i][j].w=1;
            else dis[i][j].w=0x3f3f3f3f3f3f3f3f;
            dis[i][j].cnt=1;
        }
        for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            if(i==j||i==k||j==k)continue;
            if(dis[i][k].w+dis[k][j].w<dis[i][j].w){
                dis[i][j].w=dis[i][k].w+dis[k][j].w;
                dis[i][j].cnt=dis[i][k].cnt*dis[k][j].cnt;
            }
            else if(dis[i][k].w+dis[k][j].w==dis[i][j].w)dis[i][j].cnt+=dis[i][k].cnt*dis[k][j].cnt;
        }
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(dis[i][j].cnt==2)ans++;
        cout<<ans<<endl;
    }
    return 0;
}