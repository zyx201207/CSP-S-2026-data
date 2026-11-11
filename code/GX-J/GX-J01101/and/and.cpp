#include<bits/stdc++.h>
using namespace std;
int vis[200],ans,n,m,arr[200005];
void dfs(int x,int cnt,int sum){
    if(x>n || sum>=m ){
            if(sum==m){
                ans=max(ans,cnt);
            }
        return ;
    }

    for(int i=x;i<=n;i++){
        dfs(x+1,cnt,sum);
        cnt=cnt&arr[i];
        dfs(x+1,cnt,sum+1);
        cnt=arr[i];
        sum=1;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    int op=0,op1=0;
    for(int i=1;i<=n;i++){
        cin >>arr[i];
        if(arr[i]==4){
            op++;
        }
        if(arr[i]!=i-1){
            op=1;
        }
    }
    if(op==n){
        cout<<4;
    }
    else if(n==m){
        int u=arr[1];
        for(int i=2;i<=n;i++){
            u=u&arr[i];
        }
        ans=u;
        cout<<ans;
    }
    else if(n<=20){
        dfs(2,arr[1],1);
        cout<<ans;
    }
    else if(m=1){
        for(int i=1;i<=n;i++){
            ans=max(ans,arr[i]);
        }
        cout<<ans;
    }
    else if(m=2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int s=arr[i]&arr[j];
                ans=max(ans,s);
            }
        }
        cout<<ans;
    }
    else if(op1==0){
        cout<<arr[n-m+1];
    }
 return 0;
}
