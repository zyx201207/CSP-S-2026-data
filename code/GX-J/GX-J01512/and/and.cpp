#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long a[n+10];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n);
    cout<<a[n-m];
    return 0;
}

