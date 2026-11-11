#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=n;i>=n-m;i--){
        ans^=a[i];
    }
    cout<<ans;
}
