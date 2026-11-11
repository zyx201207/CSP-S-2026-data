#include<bits/stdc++.h>
using namespace std;
int n,a[200005],k,b[200005],ma=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
    b[i]+=b[i-1]+a[i];
    }
    for(int i=1;i<=n-k+1;i++){
    
    }
    cout<<ma;
    return 0;
}
