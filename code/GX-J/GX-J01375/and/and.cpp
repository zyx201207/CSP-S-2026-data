#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],max1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            max1=max(max1,a[i]&a[j]);
        }
    }
    cout<<max1;
    return 0;
}
