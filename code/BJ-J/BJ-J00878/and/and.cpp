#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans=0;

void dfs(long long num,long long cho,long long sum)
{
    if(cho==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=num+1;i<=n;i++){
        dfs(i,cho+1,sum&a[i]);
    }
}

int main(void)
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans<<endl;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            dfs(i,1,a[i]);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
