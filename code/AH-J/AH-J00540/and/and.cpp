#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],max_v,max_a,max_b;
void dfs(long long s,long long step,long long sum){
    if(step==m){
        max_v=max(max_v,sum);
        return ;
    }
    for(int i=s+1;i<=n;i++){
        dfs(i,step+1,sum&a[i]);
    }
    return ;
}
int main(void){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0,1073741823);
    cout<<max_v;
    return 0;
}
