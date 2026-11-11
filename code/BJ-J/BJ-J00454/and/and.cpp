#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1e9;
void dfs(int step,int last,int sum){
    if(step>m){
        ans=max(ans,sum);
        return ;
    }
    if(sum<ans)return ;
    for(int i=last+1;i<=n;i++)if(sum&a[i]>ans)dfs(step+1,i,sum&a[i]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        int maxn=0;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
    }else if(m==n){
        int sum=a[1];
        for(int i=2;i<=n;i++)sum=sum&a[i];
        cout<<sum;
    }else if(m==2){
        int maxn=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
        cout<<maxn;
    }else{
        dfs(1,0,1);
        cout<<ans;
    }
    return 0;
}
