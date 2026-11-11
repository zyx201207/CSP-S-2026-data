#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,k=-1,kx=-1,l=1;
long long dfs(long long x,int y,long long z){
    long long t=-1;
    for(int i=x;i<=n-y;i++){
        if(y==1){
            t=max(t,z&a[i]);
        }
        else{
            t=max(t,dfs(x+1,y-1,z&a[i]));
        }
    }
    return t;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<n;i++){
            k=max(a[i],a[i+1]);
        }
        cout<<k;
        return 0;
    }
    if(m==n){
        k=a[1];
        for(int i=2;i<=n;i++){
            k=k&a[i];
        }
        cout<<k;
        return 0;
    }
    if(m==n-1){
        k=a[1];
        for(int i=2;i<n;i++){
            k=k&a[i];
        }
        kx=a[2];
        for(int i=3;i<=n;i++){
            kx=kx&a[i];
        }
        cout<<max(k,kx);
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                k=max(k,a[i]&a[j]);
            }
        }
        cout<<k;
        return 0;
    }
    cout<<dfs(1,m,a[1]);
    return 0;
}
