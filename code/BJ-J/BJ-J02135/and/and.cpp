#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[1000000],n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n/2+1];
    return 0;
}
