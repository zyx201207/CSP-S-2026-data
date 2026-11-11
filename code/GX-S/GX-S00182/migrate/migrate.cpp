#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL d,a[2000010];
int n,c,f[2000010],len,num;
vector<int>e[2000010];
void dfs(int x,int y,int l){
    if(l>len)return;
    if(y==x){
        if(len==l)num++;
        if(len>l)len=l,num=1;return;
    }
    for(int i=x+1;i<=y;i++)
        if(a[i]-a[x]<=d)dfs(i,y,l+1);
}
void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    //if(c<=2){
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                len=n;num=0;dfs(i,j,1);
                ans+=(num==2);
            }
        printf("%d\n",ans);
    //}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    scanf("%d%d",&c,&t);
    while(t--)
        solve();
    }
