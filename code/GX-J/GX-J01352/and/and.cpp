#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],b;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    b=a[1];
    for(int i = 2;i<=n;i++){
        b=b&a[i];
    }
    cout<<b;
    return 0;
}
