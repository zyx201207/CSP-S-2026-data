#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[n],ans=0,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
    for(int r=1;r<=x;r++){
        a[r]=y;
    }
    }

        for(int p=0;p<n/2;p++)
    if(a[n-p]!=a[p+1])
        ans++;


    cout<<ans;
    return 0;

}
