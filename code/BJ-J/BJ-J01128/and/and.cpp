#include <bits/stdc++.h>
using namespace std;
int a[10000001];
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
    int ans=a[n-1];
    //cout<<ans;
    for(int i=n-1,j=0;j<m;i--,j++){
        ans=a[i]&ans;
        //cout<<a[i]<<' '<<ans;
        //cout<<ans;
    }
    cout<<ans;
}
