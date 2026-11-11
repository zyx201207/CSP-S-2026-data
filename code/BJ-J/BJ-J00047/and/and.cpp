#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
long long a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cout<<a[n-m];
    return 0;
}
