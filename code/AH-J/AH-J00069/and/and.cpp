#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],maxn=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    cout<<maxn;
    return 0;
}
