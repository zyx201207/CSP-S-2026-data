#include <bits/stdc++.h>
using namespace std;
long long a[200010];
const long long A=4294967295;
int main() {
    int n,m;
    cin>>n>>m;
    bool ta=1,tc=1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if((a[i]&A)!=a[i]){
                ta=0;
               // cout<<a[i];
        }
    }
    sort(a,a+n);
    if(m==n) {
        long long ans=a[0];
        for(int i=1;i<m;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(ta) {
        cout<<a[0];
        return 0;
    }
    if(m==1) {
        cout<<a[n-1];
        return 0;
    }
    if(m==2){
            int ans=0;
    for(int i=0;i<n;i++) {
        
        for(int j=0;j<n;j++) {
            if(j==i)continue;
            if(ans<(a[i]&a[j]))ans=(a[i]&a[j]);
        }
    }
    cout<<ans;
    }
    return 0;
}
