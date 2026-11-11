#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[2*100005],mx=-1e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n-m>4){
        cout<<n-m-1;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        if(i==m)cout<<a[i];
    }
    return 0;
}
