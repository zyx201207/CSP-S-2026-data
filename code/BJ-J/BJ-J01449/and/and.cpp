#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0,cnt=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[n-m+1];
    return 0;
}
