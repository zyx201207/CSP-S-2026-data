#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}

