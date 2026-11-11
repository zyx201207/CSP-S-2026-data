#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
bool f=1;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        if(i!=2 && b[i-1]!=b[i]) f=0;
    }
    if(f){
        long long sum=0;
        for(int i=2;i<=n;i++){
            if(sum+b[i]*(i-1)>m) break;
            sum+=b[i]*(i-1);
            ans++;
        }
        cout << ans+1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long cnt=1,sum=0;
        for(int j=i+1;j<=n;j++){
            if(sum+b[j]*(j-i)>m) break;
            sum+=b[j]*(j-i);
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout << ans;
    return 0;
}
