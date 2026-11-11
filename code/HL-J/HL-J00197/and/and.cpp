#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+2;
int a[N],n,m,maxv;
bool vis[N];
void dfs(int cur,int temp){
    if(temp==m+1){
        maxv=max(maxv,cur);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            vis[i]=true;
            int k=cur;
            if(temp==1) k=a[i];
            dfs(k&a[i],temp+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flag=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==i-1) flag=false;
    }
    if(m==1){
        cout<<*max_element(a+1,a+n+1);
        return 0;
    }
    if(m==n){
        for(int i=2;i<=n;i++) a[1]=a[1]&a[i];
        cout<<a[1];
        return 0;
    }
    if(m==2){
        int maxv=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxv=max(maxv,a[i]&a[j]);
            }
        }
        cout<<maxv;
        return 0;
    }
    if(n<=12){
        dfs(0,1);
        cout<<maxv;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=2;i<=m;i++){
        a[1]=a[1]&a[i];
    } cout<<a[1];
    return 0;
}
