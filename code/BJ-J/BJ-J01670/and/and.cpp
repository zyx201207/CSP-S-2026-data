#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int num;
int n,m;
void dfs(int flag,int cnt,int sum,int ans){
    if(flag==n){
        num=max(num,sum);

        return ;
    }
    if(cnt==0)dfs(flag+1,0,(sum&a[flag+1]),ans-1);
    else if(ans==0)dfs(flag+1,cnt-1,sum,0);
    else if(sum!=0){
        dfs(flag+1,cnt,(sum&a[flag+1]),ans-1);
        dfs(flag+1,cnt-1,sum,ans);
    }
    else{
        dfs(flag+1,cnt,a[flag+1],ans-1);
        dfs(flag+1,cnt-1,sum,ans);
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=n-m;
    dfs(1,cnt,a[1],m-1);
    if(cnt==0){
        dfs(1,0,0,m);
    }
    else{
        dfs(1,cnt-1,0,m);
    }
    cout<<num<<endl;
    return 0;
}
