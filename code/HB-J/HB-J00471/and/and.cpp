#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=-1,sum[200005];
void dfs(int i,long long sum,int cnt){
    if(i>n)
        return;
    if(cnt==m){
        ans=max(sum,ans);
        return;
    }
    if(cnt==0){
        dfs(i+1,a[i+1],cnt+1);
        dfs(i+1,sum,cnt);
    }
    else{
        dfs(i+1,sum&a[i+1],cnt+1);
        dfs(i+1,sum,cnt);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)
            sum[i]=a[i];
        else
            sum[i]=sum[i-1]&a[i];
    }
    if(m==n-1){
        int ans=-1;
        for(int i=1;i<=n;i++){
            int x;
            if(i==1){
                x=sum[n]-sum[i];
                ans=max(ans,x);
            }
            else if(i==n){
                x=sum[n-1];
                ans=max(ans,x);
            }
            else{
                x=sum[n]-sum[i]+sum[i];
            }
        }
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
