#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    int x=a[0];
    for(int i=0;i<m;i++){
        x&=a[i];
    }
    cout << x ;
    return 0;
}
