#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
