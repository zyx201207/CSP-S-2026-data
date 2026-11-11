#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
bool check(int pos){
    long long cnt=0;
    for(int i=1;i<pos;i++) cnt+=a[pos]-a[i];
    return cnt<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long l,r,mid,ans;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    l=1;r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout << ans << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}