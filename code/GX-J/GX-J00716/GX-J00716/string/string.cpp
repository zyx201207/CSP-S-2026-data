#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int q[n];
    char e[n];
    int ns=0;
    for(int i=0;i<n;i++){
        cin>>q[i]>>e[i];
    }
    string a="";
    for(int i=0;i<n;i++){
        for(int j=0;j<q[i];j++){
            a+=e[i];
        }
    }
    int s=0;
    for(int i=0;i<=n/2;i++){
        if(a[i]!=a[n-i]){
            s++;
        }
    }
    cout<<s;
    return 0;
}



