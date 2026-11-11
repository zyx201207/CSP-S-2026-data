#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main(){
    freopen("crystal.in","r",stdin);//***********************************************************
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    long long sum=0,l=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        while(1ll*(i-l+1)*a[i]-sum>m)sum-=a[l++];
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
