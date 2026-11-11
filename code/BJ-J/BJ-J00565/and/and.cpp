#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000010];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        int ans=-1;
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=0;j<=a[i];j++){
                sum+=(a[i]>>j)&1;
            }
            ans=max(ans,sum);
        }
        cout<<ans;
    }else if(m==n){
        int ans=(a[1]&a[2]);
        for(int i=3;i<=n;i++){
            ans+=(ans&a[i]);
        }
        cout<<ans;
    }else if(m==2){
        int ans=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
    }else if(m==n-1){
        int ans=0;
        int minn=INT_MAX;
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=0;j<=a[i];j++){
                sum+=(a[i]>>j)&1;
            }
            ans+=sum;
            minn=min(minn,sum);
        }
        cout<<ans-minn;
    }
    return 0;
}
