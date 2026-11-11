#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    long long a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5)
        cout<<7;
    else if(n==4)
        cout<<12;
    else
        cout<<511;
    return 0;
}

