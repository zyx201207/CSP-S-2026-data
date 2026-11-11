#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=200005;
int a[M];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n]<<"\n";
    return 0;
}