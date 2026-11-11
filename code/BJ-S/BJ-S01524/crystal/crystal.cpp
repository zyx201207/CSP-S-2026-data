#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=500000,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=1,cnt=1;
    while(m>=cnt){
        m-=cnt;
        cnt++;
        ans++;
    }
    if(ans>=n){
        cout<<n;
        return 0;
    }
    cout<<ans;
    return 0;
}
