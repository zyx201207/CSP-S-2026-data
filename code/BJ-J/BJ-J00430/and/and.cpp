#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,mx=0;
    cin>>n>>m;
    long long a[n+10];bool x=true;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        if(a[i]>4)x=false;
    }

    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        long long ans=a[n];
        for(int i=n;i>=1;i--){
                cout<<ans<<"\n";
                ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2&&n>20){
        long long mxans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mxans=max(mxans,a[i]&a[j]);
            }
        }
        cout<<mxans;
        return 0;
    }
    sort(a+1,a+1+n);long long ans=a[n],now=0;
    for(int i=n;i>=1;i--){
        if(now==m){
            cout<<ans;
            return 0;
        }
        ans=ans&a[i];
        now++;
    }

    return 0;
}