#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int k[10000001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
    cin>>a[i];
    sort(a[i]+1,a[i]+n+1);
    for(int j=1;i<=m;i++){
        k[i]=a[i];
    }
    }
    cout<<k[m];
    return 0;
}
