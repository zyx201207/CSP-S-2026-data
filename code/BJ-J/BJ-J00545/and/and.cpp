#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=20&&m<=n||m==1||m==n||m==n-1){
        sort(a,a+n);
        int ans=a[n-1];
        //cout<<ans<<' ';
        for(int i=n-1;i>=n-m;i--){
            ans=(ans&a[i]);

        }
        cout<<ans;
    }
    else if(m==2){
        int ma=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ans=(a[i]&a[j]);
                ma=max(ma,ans);
            }
        }
        cout<<ma;
    }
    else{
        cout<<0;
    }
    return 0;
}