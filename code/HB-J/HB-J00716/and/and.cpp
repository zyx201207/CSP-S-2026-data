#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stable_sort(a+1,a+1+n);
    s=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        s=int(a[i]&s);
    }
    cout<<s;
    return 0;
}
