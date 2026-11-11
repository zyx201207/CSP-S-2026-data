#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    reopen("and.out","w",stdout);
    long long m,a[1000005],n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }cout<<a[n-1];
    return 0;
}
