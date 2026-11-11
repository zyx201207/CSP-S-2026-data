#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=a[n],c=0;
    for(int i=n;i>=n-m+1;i--)
    {
        s=s&a[i];
    }
    cout<<s;
    return 0;
}
