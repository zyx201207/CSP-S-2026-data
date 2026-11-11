#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=n-m+1;i--){
        ans=ans^(a[i]^a[i-1]);
    }
    cout<<ans;
    return 0;
}
