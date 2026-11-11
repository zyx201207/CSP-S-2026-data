#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p[500005],c;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    c = a[n-m];
    cout<<c;
    return 0;
}
