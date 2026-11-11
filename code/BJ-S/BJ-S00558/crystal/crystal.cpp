#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500050];
int ans;
int tf(int x){
    int l=1,r=x-1,mid;
    long long lenn;
    while(l<r){
        mid=(l+r)/2;
        lenn=x-mid;
        //cout<<mid<<"-"<<lenn<<" "<<a[x-1]-a[mid-1]<<endl;
      //  cout<<lenn*a[x]<<" "<<a[x]<<endl;
        if(lenn*(a[x]-a[x-1])<=a[x-1]-a[mid-1]+m){
            r=mid;
        //    cout<<1;
        }else{
            l=mid+1;
        }
    }
  //  cout<<x<<" "<<r<<endl;
    return (x-r+1);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    ans=1;
    for(int i=2;i<=n;i++){
        ans=max(ans,tf(i));
        //cout<<a[i]<<endl;
    }
    cout<<ans;
    return 0;
}
