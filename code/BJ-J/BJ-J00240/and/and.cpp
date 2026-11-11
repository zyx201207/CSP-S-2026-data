#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200100];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a-1,a+n);
    int ans=a[n-1];

    for(int i=n-2;i>=n-m;i--){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
