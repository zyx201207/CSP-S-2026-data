#include<bits/stdc++.h>
using namespace std;
int a[200005];
int vis[35];
int ans[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        p=max(p,a[i]);
    }
    if(m==1){
        cout<<p;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=30;j>=0;j--){
            if(a[i]-2^j>=0){
                vis[j]++;
                a[i]-=2^j;
            }else{
                continue;
            }
        }
    }
    for(int i=0;i<31;i++){
        if(vis[i]>=2){
            ans[i]=1;
        }
    }
    /*for(int i=0;i<35;i++){
        cout<<vis[i]<<" ";
    }*/
    long long sum=0;
    for(int i=0;i<31;i++){
        if(ans[i]==1){
            sum+=2^i;
        }
    }
    cout<<sum;
return 0;
}
