#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],nb;
long long ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        ans=a[2];
        for(int i=3;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    ans=a[n];
    for(int i=n-1;i>n-m;i--){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
