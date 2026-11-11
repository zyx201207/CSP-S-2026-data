#include<bits/stdc++.h>
using namespace std;
int m,n,maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n);
    vector<int> s(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    cout<<a[n-m];
    return 0;
}
