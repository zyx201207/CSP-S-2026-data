#include<bits/stdc++.h>
using namespace std;
    long long n,m,a[500005],dp[5005][5005],maxx=0,f[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //cout<<m<' ';
    //for(long long i=1;i<=10000000000;i++)cout<<i<<endl;
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
        for(long long j=1;j<=i;j++){
            if(m>=a[i]*(i-j+1)-(f[i]-f[j-1])){
                maxx=max(maxx,i-j+1);
                continue;
            }
        }
    }
    cout<<maxx;
return 0;}
