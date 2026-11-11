#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    cout<<a[n-k];
    return 0;
}
