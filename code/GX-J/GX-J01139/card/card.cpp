#include <bits/stdc++.h>
using namespace std;
int n,m,a[5*10^5+5],c[5*10^5+5];
set <int> b;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b.insert(a[i]);
        j=i-1;
        if(a[j]!=a[i]){
            c[i]++;
        }

    return 0;
}
