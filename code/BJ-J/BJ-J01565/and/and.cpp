#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(a[1]==0){
        cout<<0;
        return 0;
    }
    cout<<a[n-m+1];
    return 0;
}
