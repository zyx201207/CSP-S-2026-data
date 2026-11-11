#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[10005];
    long long maxi=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxi=max(a[i],maxi);
    }
    if(m==1)cout<<maxi;
    else if(m==2){
        long long ans=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    return 0;
}
