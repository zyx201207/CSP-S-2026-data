#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
