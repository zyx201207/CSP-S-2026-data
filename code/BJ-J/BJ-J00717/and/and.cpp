#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,a[300001],m,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=a[n];
    for(int i=1;i<m;i++){
        ans=ans&a[n-i];
    }
    cout<<ans;
    return 0;
}
