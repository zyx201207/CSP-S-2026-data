#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    long long m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
        if(sum[i]>m){
            cout<<i-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
//5 8
//-3 -1 2 2 7
