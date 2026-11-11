#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],x,ans;
bool _[200009];
void dfs(int step,int sum,bool type[]){
    if(step==m+1){
        ans=max(sum,ans);
        return;
    }for(int i=1;i<=n;i++){
        if(type[i]==0){
            type[i]=1;
            x=sum&a[i];
            dfs(step+1,x,type);
            type[i]=0;
        }
    }
}int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        _[i]=1;
        dfs(2,a[i],_);
        _[i]=0;
    }cout<<ans;
    return 0;
}
