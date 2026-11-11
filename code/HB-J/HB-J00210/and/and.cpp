#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int s,int l,int sum){
    if(l==m+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=s;i<=n;i++)
        dfs(i+1,l+1,sum&a[i]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int num=1;
    for(int i=1;i<=30;i++)num*=2;
    if(m==n-1){
        int sum=num;
        for(int i=1;i<=n;i++)sum&=a[i];
        for(int i=1;i<=n;i++)ans=max(ans,sum&a[i]);
        cout<<ans;
        return 0;
    }
    //cout<<num;
    dfs(1,1,num-1);
    cout<<ans;
    return 0;
}
