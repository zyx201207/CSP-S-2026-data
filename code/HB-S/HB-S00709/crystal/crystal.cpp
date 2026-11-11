#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mid,ans=1;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n/2*2==n){
        n/=2;
    }else{
        n=n/2+1;
    }
    mid=a[n];
    for(int i=n-1;i>=1;i--){
        if(mid-a[i]<=m){
            m-=(mid-a[i]);
            ans++;
        }else{
            break;
        }
    }
    n++;
    while(1){
        if(a[n]!=mid){
            break;
        }else{
            n++;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
