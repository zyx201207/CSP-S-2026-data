#include<bits/stdc++.h>
using namespace std;
long long n,a[2000000];
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[(n+1)/2];
    return 0;
}
