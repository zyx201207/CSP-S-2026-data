#include<bits/stdc++.h>
using namespace std;
int a[2001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    if(m==n){
        int ans=a[1];
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }else{
        int ans=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    return 0;
}
