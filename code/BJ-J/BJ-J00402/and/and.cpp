#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<m;i++)
    {
        cout<<a[n-m]<<endl;
    }
    return 0;
}