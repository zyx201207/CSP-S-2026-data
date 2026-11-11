#include<bits/stdc++.h>
using namespace std;
struct z{
    long long s,d;
}b[200005];
long long n,m,a[200005],k,t,p,ans;
bool vis[200005];
bool cmp(long long a,long long b){
    return a>b;
}
void dfs(long long m,long long w){
    if(m<=0){
        ans=max(ans,w);
        return;
    }
    for(int i=1;i<=p;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(m-b[i].d,w&b[i].s);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[1]){
            t=i-1;
            break;
        }
    }
    if(m<=t){
        cout<<a[1];
        return 0;
    }else if(m==n){
        k=a[1];
        for(int i=2;i<=n;i++){
            k|=a[i];
        }
        cout<<k;
        return 0;
    }
    t=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[t]){
            b[p].d++;
        }else{
            p++;
            b[p].s=a[i];
            b[p].d=1;
            t=i;
        }
    }
    dfs(m,2147483647);
    cout<<ans;
    return 0;
}
