#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
void dfs(int cur,int step){
    if(step==m){
        ans=max(cur,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!step)
            vis[i]=1,dfs(a[i],step+1);
        else if(!vis[i])
            vis[i]=1,dfs(cur&a[i],step+1);
        else
            continue;
        vis[i]=0;
    }
}
void sov1(){
    dfs(0,0);
    cout<<ans<<endl;
}
void sov2(){
    int ans=-1;
    for(int i=1;i<=n;i++)
        ans=max(ans,a[i]);
    cout<<ans<<endl;
}
void sov3(){
    int ans=a[1];
    for(int i=2;i<=n;i++)
        ans&=a[i];
    cout<<ans<<endl;
}
void sov4(){
    int ans=-1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans=max(ans,a[i]&a[j]);
    cout<<ans<<endl;
}
void sov5(){
    int ans=-1;
    for(int i=1;i<=n;i++){
        int res=(i==1?a[2]:a[1]);
        for(int j=1;j<=n;j++){
            if(j==i)
                continue;
            res&=a[i];
        }
        ans=max(ans,res);
    }
}
bool cmp(int x,int y){
    return x>y;
}
void sov6(){
    sort(a+1,a+n+1,cmp);
    cout<<a[n-m]<<endl;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=20)
        sov1();
    else if(m==1)
        sov2();
    else if(m==n)
        sov3();
    else if(m==2)
        sov4();
    else if(m==n-1)
        sov5();
    else
        sov6();
    return 0;
}