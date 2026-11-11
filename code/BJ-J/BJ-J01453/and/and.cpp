#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=n;i>=1;i--){
        if(i==n-m+1){
            cout<<a[i];
        }
    }
    return 0;
}