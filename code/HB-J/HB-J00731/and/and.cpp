#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
bool cmp(long long x,long long y){
    return x>y;
}
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=m;i++){
        if(i==1) ans=a[i];
        else ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
