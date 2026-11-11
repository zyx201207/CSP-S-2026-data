#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int l=n,r=n;
    while(l<=r && l>0){
        m = m-a[r]+a[l];
        while(m<0){
            r--;
            m = m+(r-l+1)*(a[r+1]-a[r]);
        }
        ans = max(ans,r-l+1);
        l--;

    }
    cout<<ans;
    fclose(stdout);
    fclose(stdin);
}
