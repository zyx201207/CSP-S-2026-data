#include<bits/stdc++.h>
using namespace std;
long long ans;
long long a[2005];
long long n,m;
void dfs(long long t){
    for(int i=0;i<n;i++){
        ans=max(ans,t&&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==1){
        ans=-1234567;
        for(int i=0;i<n;i++){
            ans=max(a[i],ans);
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        ans=-123456;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(a[i]&&a[j],ans);
            }
        }
        cout<<ans;
        return 0;
    }
    ans
    for(int i=0;i<m;i++){
        dfs(ans);
    }
    cout<<ans;
    return 0;
}
