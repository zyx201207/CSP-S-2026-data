#include <bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long b=a[1];
    for(int i=2;i<=m;i++){
        b=b&a[i];
    }
    cout<<b;
    return 0;
}
