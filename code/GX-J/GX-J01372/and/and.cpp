#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
    freopen("and.in","r ",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int b=a[n];
    for(int i=1;i<=m-1;i++){
        b=b&a[n-i];
    }
    cout<<b;
    return 0;

}
