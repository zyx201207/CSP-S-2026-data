#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt=1;
int main(){
    freopen(and.in,"r",stdin);
    freopen(and.out,"w",stdout);
    cin>>n>>m;
    for(int i=1;i<=30;i++)cnt*=2;
    cnt--;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m+1;i--){
        cnt=(cnt&a[i]);
    }
    cout<<cnt;
    return 0;
}
