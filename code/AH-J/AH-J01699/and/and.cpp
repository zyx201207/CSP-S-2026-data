#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]-a[n-1]==2) {
        cout<<a[n-1];
        return 0;
    }
    if(a[n]-a[n-1]==1) {
        cout<<a[n-1]-1;
        return 0;
    }
    if(a[n]-a[n-1]==3) {
        cout<<a[n-1]+1;
        return 0;
    }
    if(a[n]-a[n-1]==4) {
        cout<<a[n-1];
        return 0;
    }
    else for(int i=n;i>=n/2;i--){
        if(a[i]-a[i-1]==2) {
            cout<<a[i-1];
            return 0;
        }
    }
    cout<<a[n-3];
    return 0;
}
