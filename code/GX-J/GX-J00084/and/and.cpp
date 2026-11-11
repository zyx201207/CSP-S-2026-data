#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxn=0;
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}

