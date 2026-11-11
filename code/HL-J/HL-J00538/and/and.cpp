#include<bits/stdc++.h>
using namespace std;
long long k[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans=0x3f;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    sort(k+1,k+n+1);
    cout<<k[n-m+1];
}

