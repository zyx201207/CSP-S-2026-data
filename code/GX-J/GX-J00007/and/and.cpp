#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n ,m;
    int a[1000005];
    string a1;
    cin>>n>>m;
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}
