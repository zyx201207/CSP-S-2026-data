#include<bits/stdc++.h>
using namespace std;
int maxn=-1;
int n,m,a[200010];
bool flag[200010];
void dfs(int num,int ex){
    if(num==m){
        maxn=max(maxn,ex);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            flag[i]=1;
            dfs(num+1,ex&&a[i]);
            flag[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,1);
    cout<<maxn;
    return 0;
}
