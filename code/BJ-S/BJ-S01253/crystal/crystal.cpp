#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=1,sum=1,j=n;
    long long cnt=0;
    a[n+1]=a[n];
    for(int i=n;i>=1;i--) {
        sum--;
        cnt-=(a[i+1]-a[i])*sum;
        for(;j>=1;j--) {
            cnt+=(a[i]-a[j]);
            if(cnt>m) {
                cnt-=(a[i]-a[j]);
                break;
            }
            sum++;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
