#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxn=-0x7f7f7f7f7f7f7f7f;
void dfs(long long id,long long sum,long long lst){
    if(id==m){
        maxn=max(maxn,sum);
        return ;
    }
    for(long long i=lst+1;i<=n;i++){
        if(sum==0) dfs(id+1,a[i],i);
        else dfs(id+1,sum & a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,0,0);
    cout<<maxn;
    return 0;
}