#include<iostream>
#include<cstdio>
using namespace std;
long long a[2000010],m,ans;
int n,sum,mn,en;
void dfs(int d,int s){
    if(d==en){
        if(s==mn){
            sum++;
        }else{
            if(s<mn){
                mn=s;
                sum=1;
            }
        }
    }
    if(d==n)return;
    for(int i=d+1;i<=n;i++){
        if(a[i]-a[d]<=m)dfs(i,s+1);
        else return;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        ans=0;
        scanf("%d%lld",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                mn=10000;
                sum=0;
                en=j;
                dfs(i,0);
                if(sum==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}