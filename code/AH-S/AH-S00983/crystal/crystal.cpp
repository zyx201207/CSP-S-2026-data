#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=500005;
const long long MAXM=18e5;
int a[MAXN],pass[MAXN],cnt=0,ans=0;
void dfs(int dep,int p){
    if(dep==m){
        a[p]--;
        dep--;
        return;
    }
    a[p]++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&a[i]==a[j]){
                cnt++;
            }
        }
    }
    if((cnt/2) > ans){
        ans=cnt;
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        dfs(dep+1,i);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(1,i);
    }
    cout<<ans/2;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
}
