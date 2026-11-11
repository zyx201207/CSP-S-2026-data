#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001]={},a1[10001]={};
int ans=0;
void dfs(int s,int sum){
    if(s==0) return;
    for(int i=1;i<=n;i++){
        ans=max(ans,f1(sum,a[i]));
        if(a1[i]==0){
            a1[i]=1;
            dfs(s-1,a[i]);
            a1[i]=0;
        }
    }
}
int f1(int x,int y){
    int sum=0;
    while(1){
        if(x%2==1&&y%2==1){
            sum=sum*2+1;
        }else{
            sum=sum*2;
        }
        x/=2;
        y/=2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a1[i]=1;
        dfs(m-1,a[i]);
        a1[i]=0;
    }
    cout<<ans;
    return 0;
}
