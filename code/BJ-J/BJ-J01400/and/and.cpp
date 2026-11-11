#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
    freopen("and.in","r",stdin);
    int n,m,o;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>a[i];
    }
    cout<<a[n];
    freopen("and.out","w",stdout);
    return 0;
}

