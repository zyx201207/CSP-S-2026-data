#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdiout);
    string a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        char n1;
        cin>>m>>n1;
        for(int i=0;i<m;i++){
            a+=n1;
        }
    }
    b=reverse(a.begin(),a.end());
    for(int i=0;i<sizeof(a);i++){
        if(b[i]!=a[i]) ans++;
    }
    cout<<ans;
    return 0;
}