#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n,ans = 1,t = 1,k = 0;
long long m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;
        k += (i-t+1)*(a[i+1]-a[i]);
        if(k>m){
            long long cnt = 0;
            for(int j=t;j<=i;j++){
                long long sum = a[i]-a[j];
                cnt += sum;
                if(cnt>m){
                    ans = max(ans,j-t+1);
                    break;
                }
            }
            if(cnt<=m) ans = max(ans,i-t+1);
            t = i+1;
        }
    }
    cout<<ans;
    return 0;
}
