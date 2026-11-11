#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<long long>());
    cout<<a[m];
    return 0;
}