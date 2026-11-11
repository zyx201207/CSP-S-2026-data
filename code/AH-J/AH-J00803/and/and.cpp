#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    cout<<a[n/2+1];
    return 0;
}
