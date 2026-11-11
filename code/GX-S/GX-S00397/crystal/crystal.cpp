#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;
long long m,sum;
long long a[N],p[N];
int l,r,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        p[i] = a[i] - a[i-1];
    }
    p[1] = 0;
    l = 1;r = 1;sum = 0;
    for(int i=1;i<=n;i++){
        while((sum+p[r+1]*(r-l+1) <= m) && (r+1 <= n)){
            sum += p[r+1]*(r+1-l);
            r++;
        }
        if(r-l+1 > ans)ans = r-l+1;
        //cout<<"l,r,sum = "<<l<<" "<<r<<" "<<sum<<"\n";
        sum -= (a[r]-a[l]);
        l++;
    }
    cout<<ans<<"\n";
    return 0;
}
