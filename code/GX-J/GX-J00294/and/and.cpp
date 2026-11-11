#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[i]>a[i-1])
        {
            cout<<a;
        }
    }
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    return 0;
}
