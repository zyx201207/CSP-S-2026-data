#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[200010],maxn,b[200010];
void dfs(LL cur,LL cnt,LL ans){
    if(cnt==m){
        maxn=max(maxn,ans);
        return ;
    }
    if(cur>n)return ;
    dfs(cur+1,cnt,ans);
    if(cnt==0)dfs(cur+1,cnt+1,a[cur]);
    else dfs(cur+1,cnt+1,ans&a[cur]);
}
bool ok(){
    for(LL i=1;i<=n;i++){
        LL x=a[i]+1;
        while(x>1){
            if(x%2==0)x/=2;
            else{
                return 0;
            }
        }
    }
    return 1;
}
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,0,0);
        cout<<maxn;
        return 0;
    }
    if(m==1){
        for(LL i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n){
        LL ans=a[1];
        for(LL i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(LL i=1;i<=n;i++){
            LL ans=0;
            for(LL j=i+1;j<=n;j++){
                if(i==j)continue;
                ans=a[i]&a[j];
                maxn=max(maxn,ans);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1){
        for(LL i=1;i<=n;i++){
            LL ans=0,cnt=0;
            for(LL j=1;j<=n;j++){
                if(j==i)continue;
                cnt++;
                if(cnt==1)ans=a[j];
                else ans=ans&a[j];
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn;
        return 0;
    }
    if(ok()){
        for(LL i=1;i<=n;i++){
            LL x=a[i]+1,cnt=0;
            while(x>1){
                x/=2;
                cnt++;
            }
            b[i]=cnt;
        }
        sort(b+1,b+n+1,cmp);
        for(LL i=1;i<=n;i++){
            if(i==m){
                cout<<pow(2,b[i])-1;
            }
        }
    }
    return 0;
}
