#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
int n,m,a[N],cnt[N],ans,flg;
void dfs(int t,int aa,int res){
    if(aa>m)return;
    if(t==n+1){
        if(aa==m)ans=max(res,ans);
        return;
    }
    dfs(t+1,aa+1,res&a[t]);
    dfs(t+1,aa,res);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        int maxv=0;
        for(int i=1;i<=n;i++)
            maxv=max(a[i],maxv);
        cout<<maxv<<endl;
    }else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans<<endl;
    }else if(m==n-1){
        int qian[N],hou[N];
        qian[1]=a[1];
        for(int i=2;i<=n;i++)
            qian[i]=qian[i-1]&a[i];
        hou[n]=a[n];
        for(int i=n-1;i>=1;i--)
            hou[i]=hou[i+1]&a[i];
        ans=hou[2];
        for(int i=2;i<n;i++)
            ans=max(qian[i-1]&hou[i+1],ans);
        ans=max(qian[n-1],ans);
        cout<<ans<<endl;
    }else{
        dfs(1,0,2e30-1);
        cout<<ans<<endl;
    }
    return 0;
}
