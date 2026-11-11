#include<bits/stdc++.h>
using namespace std;
int a[200005];
int maxx=0;
int n,m;
void dfs(int sum,int s,int t){
    if(s==m){
        maxx=max(maxx,sum);
        return ;
    }
    if(t==n)return ;
        dfs(sum&a[t+1],s+1,t+1);
        dfs(sum,s,t+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    dfs(a[i],1,i);
}
cout<<maxx;
return 0;
}
