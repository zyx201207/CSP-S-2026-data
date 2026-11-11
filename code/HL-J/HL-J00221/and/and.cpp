#include <bits/stdc++.h>
using namespace std;
long long a[100000009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ma=a[n-1];
    cout<<ma;
    return 0;
}
