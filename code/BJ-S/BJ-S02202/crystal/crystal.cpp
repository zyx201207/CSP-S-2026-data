#include<bits/stdc++.h>
using namespace std;
long long m,a[200005],s[200005];
int ans,n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<n<<"     "<<m;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long cnt=0;
        int j=i-1;
        for(;j>=1;j--){
            cnt+=a[i]-a[j];
            if(cnt>m){
                j++;
                break;
            }
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
