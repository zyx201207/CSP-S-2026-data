#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;int a[1000005];bool flag=1;
    for(int i=0;i<n;i++){
        cin>>a[i];if(a[i]%2==0) flag=0;
    }
    sort(a,a+n);
    if(flag==1) cout<<a[n-m];
    else if(m==1) cout<<a[n-1];
    else cout<<0;
    return 0;
}
