#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[200005];
int ans=0;
void dfs(int last,int k,int zh){
    if(last==n||k>m){
        if(k>m){
            ans=max(ans,zh);
        }
        return;
    }if(zh<ans){
        return;
    }
    for(int i=last+1;i<=n;i++){
        int x= zh & arr[i];
        dfs(i,k+1,x);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i+m<=n;i++){
        dfs(i,2,arr[i]);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
