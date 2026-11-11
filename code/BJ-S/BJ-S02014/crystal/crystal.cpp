#include <bits/stdc++.h>

using namespace std;
int n;
long long m;
long long a[500005];
long long f[500005];
long long sum=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    for(long long i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            long long left=j,right=j+i-1;
            long long ans=(right*a[right]-f[right])-left*a[right]+f[left];
            if(ans>m) continue;
            else sum=max(sum,i);
        }
    }
    cout<<sum;
    return 0;
}
