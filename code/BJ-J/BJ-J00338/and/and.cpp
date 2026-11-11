#include<bits/stdc++.h>
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
    if(m==1)
    {
        int mx=-2e9;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }
    else{
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }
    return 0;
}