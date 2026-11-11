#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long maax=-1;
    for(int i=0;i<=n;i++){
        for(int ii=i+1;ii<=n;ii++){
            if(a[i]&a[ii]>=maax)maax=a[i]&a[ii];
        }
    }
    cout<<maax;
    return 0;
}