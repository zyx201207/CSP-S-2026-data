#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
long long ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    ans=a[0];
    for(int i=1;i<m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
