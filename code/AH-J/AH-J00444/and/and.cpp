#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],b,ans=0;
bool sham=1,shbm=1;
ll dfs(int nn,int mm){
    if(1) return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i==1) b=a[i];
        else b&=a[i];
        if(!sham||(a[i]!=a[i-1]*2&&i>1)) sham=0;
        if(!shbm||(a[i]!=a[i-1]+1&&i>1)) shbm=0;
    }
    if(sham) return cout<<a[n],0;
    sort(a+1,a+n+1);
    if(m==1) return cout<<a[n],0;
    if(m==n) return cout<<b,0;
    if(m==2){
        b=-1;
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j) b=max(b,a[i]&a[j]);
        return cout<<b,0;
    }
    if(m==n-1){
        for(int i=1;i<=n;++i){
            if(i==1) b=a[2];
            else b=a[1];
            for(int j=2;j<=n;++j){
                if(j!=i) b&=a[i];
            }
            ans=max(ans,b);
        }
    }
    /*if(n<=20){
        cout<<dfs(1,0);
    }*/
    b=a[1];
    for(int i=2;i<=m;++i) b&=a[i];
    cout<<b;
    return 0;
}
