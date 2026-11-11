#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
//int v[200010];
long long ans;
void dfs(int deep,long long sum,int ind){
    if(deep>m){
        return ;
    }
    if(deep==m){
        ans=max(ans,sum);
        //cout<<1<<endl;
        return ;
    }
    if(deep+n-ind<m-1){
        return ;
    }
    if(ind>n){
        return ;
    }
    if(deep==0){
        sum=a[ind];
    }
    //cout<<ind<<" ";
    dfs(deep+1,sum&a[ind],ind+1);
    dfs(deep,sum,ind+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
