#include <bits/stdc++.h>
using namespace std;
long long m,n;
const int k=2e5;
long long max1=0;
long long max2=0;
int a[k]={0};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());


    for(int i=0;i<m-1;i++){
        max1=a[i];
        max2=max1&a[i+1];

    }
    cout<<max2;

    return 0;


}
