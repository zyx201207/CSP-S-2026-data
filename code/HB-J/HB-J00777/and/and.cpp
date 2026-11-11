#include<bits/stdc++.h>
using namespace std;
int n,m;
bool v[210005];
int a[210005];
int ans=0,mans=-INT_MAX;
int cnt=0;
void dfs(int x,int fa,int d){
    cnt+=1;
    if(cnt==1e9){
            cout<<mans;
            return ;
    }
    if(d==m)mans=max(ans,mans);
for(int i=1;i<=n;i++){
        if(d==1)ans=a[i];
    if(v[i]==0){
        v[i]=1;
        ans=ans||a[i];
        dfs(i,x,d+1);
        v[i]=0;
    }
}
}
int main(){
//freopen("and5.in","r",stdin);
//freopen("and5.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(m==n){
        int sum=a[1];
    for(int i=2;i<=n;i++){
        sum=sum||a[i];
    }cout<<sum;
    return 0;
}
if(m==1){
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}
dfs(1,0,1);
cout<<mans;
return 0;
}

