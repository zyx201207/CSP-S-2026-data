#include<bits/stdc++.h>
using namespace std;
long long n,b,mx=INT_MIN;
int a[100005],v[100005];
void dfs(int in,int num,int ans,int c){
    if(num==ans){
        long long sum=c&in;
        mx=max(sum,mx);
        return ;
    }
    for(int i=1;i<=in-num;i++){
        if(v[i]==0){
            v[i]=1;
            dfs(a[i],num+1,ans,c);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        v[i]=1;
        dfs(a[i],1,b,a[i]);
    }
    cout<<mx;
    return 0;
}
