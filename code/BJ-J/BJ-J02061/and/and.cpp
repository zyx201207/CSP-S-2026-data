#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[200005];
int n,m;
int main(){
    freopen("and5.in","r",stdin);
    freopen("and5.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[n-m+1];
    return 0;
}
