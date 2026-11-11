#include <bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long a[500005];
unsigned long long s[500005];
int lb(int i){
    int l=1,r=i;
    while(l<r){
        int mid=l+r>>1;
        if(s[i]-s[mid-1]-(mid-1)*(a[i]-a[mid-1])<=m)r=mid;
        else l=mid+1;
    }
    return i-l+2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool _=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i+1]-a[i];
        s[i]*=i;
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;i++){
        if(i<n&&a[i+1]-a[i]<=m)_=1;
        ans=max(ans,lb(i));
    }
    cout<<(_?ans:0);
    return 0;
}
