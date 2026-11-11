#include<bits/stdc++.h>
using namespace std;

long long a[10010];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
        return 0;
    }
    long long ans;
    ans = a[n-1]&a[n-2];
    for(int i=n-3;i>n-m-1;i--){
        ans = ans&a[i];
    }
    cout<<ans;
    return 0;
}
