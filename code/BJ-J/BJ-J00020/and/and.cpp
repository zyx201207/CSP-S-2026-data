#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>=y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a[200005];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+1+n,cmp);
    cout<<a[m];
    return 0;
}
