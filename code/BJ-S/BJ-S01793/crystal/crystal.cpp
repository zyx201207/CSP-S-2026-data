#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500001],s[500001];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++) s[i]=a[i]-a[i-1];
    int sum=0,cnt=0;
    for(long long i=1;i<n;i++){
        sum+=s[i];
        if(sum<=m) cnt++;
        else break;
    }
    cout << cnt;

    return 0;
}
