#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mx=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=i+m;j++){
            mx=max(mx,a[j]&a[i]);
        }
    }
    cout<<mx-3;

    return 0;
}
