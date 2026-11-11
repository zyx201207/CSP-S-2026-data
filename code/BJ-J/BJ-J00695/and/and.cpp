#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n-1]|a[n-2];
    return 0;
}
