#include <bits/stdc++.h>
using namespace std;
const int N=2.1e5;
long long n,m,a[N];
int cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long c=a[1];
    for(int i=1;i<m;i++){
        c&=a[i+1];
    }
    cout<<c<<endl;
}