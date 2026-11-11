#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1) cout<<a[n-1];
    else cout<<a[n-m];
    return 0;
}
