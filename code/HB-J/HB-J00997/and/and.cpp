#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
long long ans=-1;
int h=-1;
int n,m;
int dfs(int i,int yi,int sum){
    if(b[i]!=0){
        return b[i];
    }
    if(yi==m){
        return sum;
    }
    if(i==n){
        return 0;
    }
    return b[i]=dfs(i+1,yi+1,sum&a[i]);
    return b[i]=dfs(i+1,yi,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==n){
        cin>>ans;
        for(int i=2;i<=n;i++){
            cin>>a[i];
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //a[i]=a[i-1]^b;
    }
    for(int i=1;i<=n;i++){
        h=max(dfs(i,1,a[i]),h);
    }
    cout<<h;
    return 0;
}
