#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    long long n , m;
    cin>>n>>m;
    long long a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1 , a+n+1);
    cout<<a[n-m+1]<<endl;
    return 0;
}
