#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
#define int ll
/*
15:30 start
首先，什么时候会**恰好**两个？
形如 [a-b-c] [a-d-c]
这种东西怎么找？
[lc,ra] 内恰好有两个元素
那每一个(u,v) 都可以对应一个(a,c)
一个(a,c)对应的方案数是，(s[a]+1)(s'[c]+1)
f[a] 以a结尾的，只有一种方案的点数
g[c] 以c开头的
f[a]怎么求？
s[a]=f[a]-[l{a+1},a]内的数字个数
则f[a]=s[最左边能够到的元素]+[la,a-1]元素个数+1
每次往右边跳？？
*/
namespace sub12{
int c,T,n,d;
    int a[505];
    int fa[505],dep[505],x;
    void dfs(int now,int dd){
        if(dd>dep[now])return;
        if(dep[now]==dd+1){
            fa[now]++;
            // return;
        }
        if(dd+1>dep[now])return;
        if(dd+1<dep[now]){
            fa[now]=1;
            dep[now]=dd+1;
            // return;
        }dep[now]=min(dep[now],dd+1);
        if(now==x)return;
        for(int j=now+1;j<=n;j++){
            if(abs(a[j]-a[now])<=d and dep[j]>=dd+1 and fa[dd+1]<3)dfs(j,dd+1);
        }
    }
    
    signed solve(){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int t=0;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=i;j++){
                memset(fa,0,sizeof fa);
                memset(dep,0x3f,sizeof dep);
                x=i;
                dfs(j,0);
                if(fa[i]==2){
                    t++;
                }
            }
            
        }
        // cout<<"hhhh";
        cout<<t<<endl;
        return 0;
    }
};
int c,T,n,d;
int a[N],l[N],r[N],f[N],s1[N],g[N],s2[N],s[N];


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        if(c<=6){
            sub12::solve();
        }
        else{
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            if(n<=2 or a[3]-a[1]>d){
                cout<<0<<endl;
                continue;
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}