#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],max_=-1;
int main(){
  freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max_=max(max_,a[i]);
    }
    if(m==1){
        cout<<max_;
        return 0;
    }
    return 0;
}
//CCRHFBEHHDFHUWEHBUSHUUFVEDAHOEGYASOIXIEDHrn8EVFUHOSAFFVBAUIR

