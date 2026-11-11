#include <bits/stdc++.h>
using namespace std;
int n,x,a[20005],num=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-x];
    return 0;
}
