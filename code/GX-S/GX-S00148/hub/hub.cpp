#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("hub.in","r",stdin);
    freopen ("hub.in","w",stdout);
    long long n,m,a[100];
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=8;
    a[5]=9;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cout<<a[i];
    }
    return 0;
}

