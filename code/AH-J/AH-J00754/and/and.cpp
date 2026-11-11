#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200000005],k;
bool hmh(const int &a,const int &b)
{
	return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,hmh);
    k=a[1];
    for(int i=2;i<=m;i++) k=k&a[i];
    cout<<k;
    return 0;
}
