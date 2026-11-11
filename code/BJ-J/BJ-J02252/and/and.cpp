#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m,n,a[100010];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cmp(a+1,a+n+1);
    cout<<a[m];
    return 0;
}

