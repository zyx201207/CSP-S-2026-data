#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0,l=0;i<n;i++){
        if(l<i)k-=(i-l)*(a[i]-a[i-1]);
        while(l<=i&&k<0)k+=a[i]-a[l],l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}

