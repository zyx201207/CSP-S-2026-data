#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int c,t;
int n,d;
int a[N];
int lt[N][N];
int zj[N];
int ans;
bool check(int l,int r){
    if (a[r]-a[l]<=d) return true;
    return false;
}
int ef(int z){ //zuo,feixingjuli
    if (zj[z]!=0) return zj[z];
    int l=z,r=n;
    while (l<r){
        // cout << l << " " << r << endl;
        int mid=(l+r+1)>>1;
        if (check(z,mid)==true) l=mid;
        else r=mid-1;
    }
    return zj[z]=l;
}
int cnt=0;
bool dfs(int u,int v,int step){
    if (u==v and step==0) return true;
    if (u==v or step==0) return false;
    if (a[v]-a[u]<=d and step==1) return true;
    else if (a[v]-a[u]<=d or step==1) return false;
    int mx=ef(u);
    // if (n==4 and v==4 and u==2) cout << "mx:" << mx << " step:" << step << endl;
    for (int i=mx;i>u;i--){
        // if (n==4 and v==4 and u==2) cout << "i:" << i << " step:" << step <<endl;
        if (dfs(i,v,step-1)==true) cnt++;
        else break;
    }
    return true;
}
int zd(int u,int v){
    if (u>=v) return 0;
    // if (a[v]-a[u]<=d) return 1;
    // if (a[v]-a[u]>d and v==u+1) return -1;
    int mz=ef(u);
    if (mz==u) return -1;
    if (zd(mz,v)==-1) return -1;
    return 1+zd(mz,v);
}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while (c>'9' or c<'0'){
        if (c=='-'){
            f=-1;
            c=getchar();
        }
    }
    while (c<='9' and c>='0'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while (t--){
        ans=0;
        memset (lt,0,sizeof(lt));
        memset (zj,0,sizeof(zj));
        n=read(),d=read();
        for (int i=1;i<=n;i++) a[i]=read();
        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                lt[i][j]=zd(i,j);
                // if (n==6)printf ("i:%d j:%d lt:%d\n",i,j,lt[i][j]);
                // fflush(stdout);
            }
        }
        // cout << zd(4,5);
        // cout << ef(3);
        for (int i=1;i<=n-3;i++){
            for (int j=i+3;j<=n;j++){
                if (lt[i][j]==-1) break;
                dfs(i,j,lt[i][j]);
                // if (i==1 and j==4) cout << "cnt:" << cnt << endl;
                if (cnt==2) ans++;
                cnt=0;
            }
        }
        cout << ans << endl;
        // cout << ef(2);
        // if (dfs(4,4,0)==true and n==4) cout << "sfud" << endl;
    }
    // cout << "woshizhizhang";
    return 0;
}
/*
kou->zhanting->zhantai!!!
j=i+3;
j<=n;
i+3<=n;
i<=n-3;
*/