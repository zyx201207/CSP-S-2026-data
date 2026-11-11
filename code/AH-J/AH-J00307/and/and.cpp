#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m,sum;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    cout<<a[m];
    return 0;
}
