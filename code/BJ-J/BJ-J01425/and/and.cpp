#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    int a[100005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ans=a[n-1];
    for(int i=n-2;i>=n-m;i--){
        ans=(ans&a[i]);
    }
    cout<<ans;
}
