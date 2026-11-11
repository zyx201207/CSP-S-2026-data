#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005],ans=0;
void dfs(int now,int sum,int cnt){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=now+1;i<=n;i++){
        if(now==0) dfs(i,a[i],cnt+1);
        else dfs(i,a[i]&sum,cnt+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>2000){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}


