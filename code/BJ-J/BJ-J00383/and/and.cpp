#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    ans=a[1];
    for(int i=1;i<=m;i++){
        ans=(ans&a[i]);
    }
    cout<<ans<<endl;
    return 0;
}