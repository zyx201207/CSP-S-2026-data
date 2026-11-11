#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    cin>>n>>m;
    long long a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long cnt=0,ans=0,h=2;
    for(long long i=2;i<=n;i++){
        long long i2=i+2-h;
        cnt=cnt+(a[i]-a[i-1])*(i2-1);
        long long h2=h;
        while(h<=i&&m<cnt){
            ans=max(i+2-h-1,ans);
            cnt-=(a[i]-a[h-1]);
            h++;
        }
        if(h<=i) ans=max(ans,i+2-h);
    }
    cout<<ans;
    return 0;
}
