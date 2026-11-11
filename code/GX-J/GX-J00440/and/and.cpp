#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100004];
    int maxh=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxh=max(maxh,a[i]);
    }
    if(m==1){
        cout<<maxh;
        return 0;
    }
    if(m==2){
      int ans=0;
      for(int i=1;i<n;i++){
            int sum=0;
            for(int j=i+1;j<n;j++){
                sum=a[i]&a[j];
                ans=max(ans,sum);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        int sum=a[1],ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                ans&=a[j];
            }
            ans=max(ans,sum);
        }
        cout<<ans;
        return 0;
    }
    else {
        int ans=0;
        for(int i=1;i<n;i++){
            int sum=s[i];
            for(int j=i+1;j<i+m;j++){
                sum&=a[j];
            }
            ans=max(ans,sum);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}





