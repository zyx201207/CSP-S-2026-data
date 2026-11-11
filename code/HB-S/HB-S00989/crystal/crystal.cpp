#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    return 0;
}
