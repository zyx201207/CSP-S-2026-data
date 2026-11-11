#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
bool sort1(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,sort1);
    for(int i=2;i<=m;i++)
    {
        a[i]=a[i-1]&a[i];
    }
    cout<<a[m];
    return 0;
}
