#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1000;
long long a[maxn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-m];
}
