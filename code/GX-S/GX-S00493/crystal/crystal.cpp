#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500019];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll ans=1,res=0;
    a[n+1]=a[n];
    for(int i=n;i>=1;i--){
        m+=ans*(a[i+1]-a[i]);
        ans--;
        int j=i-ans-1;
        while(j>0){
            if(m<a[i]-a[j]) break;
            m-=a[i]-a[j];
            ans++;
            j--;
        }
        res=max(res,ans);
    }
    cout<<res+1;
    return 0;
}
