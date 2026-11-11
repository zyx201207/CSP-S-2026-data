#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int n,m;
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
