#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n,m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<a[i]<<" ";
    }
    ans=a[n];
    cout<<ans;
    return 0;
}
