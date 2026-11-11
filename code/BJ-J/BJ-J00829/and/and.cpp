#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans,n,m;
void dfs(int step,int cnt,int sum){
    if(step>n) return;
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }

    if(cnt==0) dfs(step+1,cnt+1,a[step]);
    else dfs(step+1,cnt+1,(sum&a[step]));

    dfs(step+1,cnt,sum);
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
    }else if(m==n-1){
        int ans=0;
        for(int i=1;i<=n;i++){
            int sum;
            if(i==1) sum=a[2];
            else sum=a[1];
            for(int j=1;j<i;j++){
                sum=(sum&a[j]);
            }
            for(int j=i+1;j<=n;j++){
                sum=(sum&a[j]);
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }else if(n<2000){
        dfs(1,0,0);
        cout<<ans;
    }else{
        sort(a+1,a+1+n,greater<int>());
        int ans=a[1];
        for(int i=2;i<=m;i++){
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}
