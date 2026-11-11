#include<iostream>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    long long n,m,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<a[n];
    freopen("and.out","w",stdout);
    return 0;
}
