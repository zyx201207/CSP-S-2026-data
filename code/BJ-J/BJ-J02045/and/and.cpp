#include<iostream>
#define int long long
const int N=2e5+5;
using namespace std;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[N];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m=1){
        sort(a,a+n);
        cout<<a[n];
    }
    
    return 0;
}
