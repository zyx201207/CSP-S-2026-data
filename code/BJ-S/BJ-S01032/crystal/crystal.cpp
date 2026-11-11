#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500050],cf[500050],qzh[500050],sum=0,ans=INT_MIN;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (long long i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if (a[1]==a[n]){
        cout << n;
        return 0;
    }
    memset(cf,0,sizeof(cf));
    for (long long i=2;i<=n;i++){
        cf[i]=a[i]-a[i-1];
    }
    sum=0;
    for (long long i=1;i<=n;i++){
        sum+=(cf[i]*(i-1));
        qzh[i]=qzh[i-1]+(cf[i]*(i-1));
    }
    if(m>=sum){
        cout << n; return 0;
    }

    for (long long i=1;i<=n;i++){
        for (long long j=i;j<=n;j++){
            long long l=i,r=j;
            long long num=qzh[r]-qzh[l-1]-((a[r]-a[l-1])*(l-1));
            if (m>=num){
                ans=max(ans,r-l+1);
            }
        }
    }
    cout << ans;
    return 0;
}
