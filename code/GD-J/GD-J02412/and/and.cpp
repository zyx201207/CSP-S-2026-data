#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans;
long long f(int x){
    int ans=1;
    for(int i=1;i<=x;i++){
        ans*=2;
    }
    return ans;
}
long long fun(int x,int y){
    int ans=0,cnt1=1,cnt2=1;
    char xx[64],yy[64];
    while(x){
        xx[cnt1++]=x%2+'0';
        x/=2;
    }
    while(y){
        yy[cnt2++]=y%2+'0';
        y/=2;
    }
    for(int i=1;i<=max(cnt1,cnt2);i++){
        if(xx[i]=='1' and yy[i]=='1') ans+=f(i-1);
    }
    return ans;
}
void dfs(int t,int step,long long sum){
    if(step>m){
        ans=max(ans,sum);
        return;
    }
    for(int i=t;i<=n;i++){
        dfs(i+1,step+1,fun(sum,a[i]));
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,fun(a[1],a[2]));
    freopen("and.out","w",stdout);
    cout<<ans;
}
