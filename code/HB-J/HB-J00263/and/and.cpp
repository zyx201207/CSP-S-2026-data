#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,k;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long max1 = -1;
    sort(a+1,a+n+1);
    max1 = a[n];
    while(k>1){
        max1 = max1 & a[n-k+1];
        k--;
    }
    cout<<max1;
    return 0;
}
