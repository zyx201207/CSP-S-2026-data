#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans;
ll a[500005],f[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    //cout << 1 << endl;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    //cout << n << " " << m << endl;
    for(int i=1;i<=n;i++){
        ll sum=a[i]*(i-1)-f[i-1];
        if(sum>m){
            int t=m;
            //cout << t << endl;
            int j=i-1,cnt=0;
            ans=max(ans,cnt);
        }
        else ans=max(ans,i);
    }
    cout << ans << endl;
    return 0;
}
//CCF=Chinese Can Fly 
