#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long dp[500005];

bool ck(int x){
    for(int i=x;i<=n;i++){
        long long m1=dp[i]-dp[i-x+1]-(a[i]-a[i-x+1])*(i-x);
        if(m1<=m) return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    if(n==1){
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int l=1,r=n+1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(ck(mid)==1){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout << l;
    return 0;
}
