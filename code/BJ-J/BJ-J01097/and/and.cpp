#include<bits/stdc++.h>
using namespace std;
long long n,m,s,k=1,ans,a[200009];
void dfs(long long i,long long u,long long q){
    if(i==n+1){
        if(!u)ans=max(ans,q);
        return;
    }
    if(q==-1){
        dfs(i+1,u,-1);
        dfs(i+1,u-1,a[i]);
    }
    else{
        dfs(i+1,u,q);
        dfs(i+1,u-1,q&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s=a[1];
    if((long long)pow(2,sqrt(a[1]+1))!=a[1]+1)k=0;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s&=a[i];
        if((long long)pow(2,sqrt(a[i]+1))!=a[i]+1)k=0;
    }
    sort(a+1,a+1+n);
    if(k)cout<<a[n];
    else if(m==1)cout<<a[n];
    else if(m==n)cout<<s;
    else if(m==2){
        int v=1;
        for(int i=n;i>=1;i++){
            if((long long)pow(2,sqrt(a[i]))==(long long)pow(2,sqrt(a[i-1]))){
                    cout<<(a[i]&a[i-1]);
                    v=1;
                    break;
            }
        }
        if(v)cout<<(a[n]&a[n-1]);
    }
    else{
        dfs(1,m,-1);
        cout<<ans;
    }
    return 0;
}
