//GZ-J00636 µË²ıª
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20000005],sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum=a[n-m+1];
    for(long long i=n-m+1;i<=n;i++){
        sum=(sum&a[i]);
    }
    cout<<sum;
    return 0;
}
