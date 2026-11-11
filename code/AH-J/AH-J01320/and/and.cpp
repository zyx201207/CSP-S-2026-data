#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
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
        long long ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }else if(m==2){
        long long ans1=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans1=max(ans1,(a[i]&a[j]));
            }
        }
        cout<<ans1;
    }else if(m==n){
        long long ans2=a[1];
        for(int i=2;i<=n;i++){
            ans2=ans2&(a[i]);
        }
        cout<<ans2;
    }
    return 0;
}
