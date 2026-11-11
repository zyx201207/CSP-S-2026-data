#include<bits/stdc++.h>
#define ll long long
#define MAX 1000010
using namespace std;
int n,m;
int a[MAX];
int ans;
void dfs(int x,int p,int sum){
    if(x==n+1){
        if(m==p){
            ans=max(ans,sum);
        }
        return ;
    }
    if(p==m){
        ans=max(ans,sum);
        return ;
    }
    if(p>m) return ;
    dfs(x+1,p+1,sum&a[x]);
    dfs(x+1,p,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans<<"\n";
        return 0;
    }
    if(n>2000){
        int maxn=-1;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn<<"\n";
        return 0;
    }
    ans=-1;
    dfs(1,0,INT_MAX);
    cout<<ans<<"\n";
    return 0;
}
