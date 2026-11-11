#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ans=(a[n-1] & a[n-2]);
    int i;
    for(i=3;i<=m;i++){
        ans=(ans & a[n-i]);
    }
    cout<<ans;
    return 0;
    }
