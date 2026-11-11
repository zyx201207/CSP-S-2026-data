#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[a[i]]++;
    }
    sort(b+1,b+n+1);
    cout<<b[n]+2;
    return 0;
}
