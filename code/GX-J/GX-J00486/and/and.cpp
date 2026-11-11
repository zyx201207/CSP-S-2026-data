#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int a[N];
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
    cout<<a[n-m];
    return 0;
}
