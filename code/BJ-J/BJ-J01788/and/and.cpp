#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
ll n,m,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> tad;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[n-m+1];

    return 0;
}