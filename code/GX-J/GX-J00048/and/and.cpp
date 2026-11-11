#include <bits/stdc++.h>
using namespace std;

long long a[100000],b[100000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long maxn=a[i-1];
        b[i-1]=max(maxn,a[i]);
        cout<<b[m];
    }

    return 0;
}
