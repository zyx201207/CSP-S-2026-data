#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n;
    long long m;
    cin>>m;
    int ans=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool f=0;
    for (int i=2;i<n;i++){
        if (a[i+1]-a[i]!=a[i]-a[i-1])f=1;
    }
    if (f==1){
        for (int i=2;i<=n;i++){
            b[i]=a[i]-a[i-1];
        }
        b[1]=0;
        for (int l=1;l<=n;l++){
            long long sum=0;
            for (int r=l;r<=n;r++){
                sum+=b[r]*(r-l);
                if (sum<=m)ans=max(ans,r-l+1);
            }
        }
        cout<<ans;
    }
    else {
        int cnt=0;
        cnt=a[2]-a[1];
        long long l=0;
        while (l<=m){
            l+=cnt+l;
            ans++;
        }
        cout<<ans;
    }
    return 0;
}
